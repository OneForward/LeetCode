import requests, requests_cache
from lxml import etree

def remove_white(s):
    return ' '.join(s.split())

def fetch_lessons(base, lessons_url):
    resp = requests.get(base + lessons_url)
    tree = etree.HTML(resp.text)
    tags = tree.xpath('/html/body/div[1]/div[3]/div/div[1]/a')
    lessons = [fetch_lesson(tag) for tag in tags]
    data = {}
    for (title, url) in lessons:
        ps = fetch_problems(base, url)
        for p_title, p_synopsis, p_content, p_url in ps:
            data[p_title] = (p_title, p_synopsis, p_content, p_url, title, base + url)
    return data

def fetch_lesson(tag):
    url = tag.get('href')
    title = ' '.join(div.text for div in tag.xpath('div'))
    return title, url 

def fetch_problems(base, lesson_url):
    url = base + lesson_url
    try:
        resp = requests.get(url)
    except:
        print(f'fetch {url} failed')
        return 
    print(f'ok {url}')
    tree = etree.HTML(resp.text)
    ps = tree.xpath('/html/body/div[1]/div[3]/div/div[2]/div[3]/div')
    ps += tree.xpath('/html/body/div[1]/div[3]/div/div[2]/div[2]/div')
    data = []
    for p in ps:
        p_url = p.xpath('div[2]/div[1]/div[1]/h4/a')[0]
        p_title = remove_white(p_url.text)
        p_url = base + p_url.get('href')
        p_synopsis = remove_white(p.xpath('div[2]/div[2]')[0].text)
        p_content = fetch_problem_content(p_url)
        data.append((p_title, p_synopsis, p_content, p_url))
    return data

def fetch_problem_content(p_url):
    try:
        resp = requests.get(p_url)
    except:
        print(f'fetch {p_url} failed')
        return ''
    print(f'ok {p_url}')
    tree = etree.HTML(resp.text)
    try:
        div = tree.xpath('/html/body/div[1]/div[3]/div/div[2]/div[2]/div[2]/div[5]/div[1]')[0]
    except:
        print(f'fetch {p_url} content failed')
        return ''
    s = []
    for p in div.iterdescendants():
        ptext = p.text
        if ptext == 'Write an ': break
        if ptext: s.append( f'{ptext}' )
    return '\n'.join(s)

if __name__ == '__main__':
    requests_cache.install_cache('codility')
    base = 'https://app.codility.com'
    alldata = fetch_lessons(base, '/programmers/lessons')
    import pickle 
    with open('codility_data.pkl', 'wb') as f:
        pickle.dump(alldata, f)



