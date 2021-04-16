import path, sys , subprocess, json
sys.stdout = open(f"../README.md", "w")

# subprocess.run("powershell -ExecutionPolicy ByPass -File FetchLeet.ps1".split())
# likes = json.loads(open('LeetCodeLikes.json',  encoding='utf-16').read())['questions']
# likes = set(Q['id'] for Q in likes)
import pickle
likes = pickle.load(open('likes.pkl', 'rb'))


alldata = json.loads(open('LeetCodeProblems-ZN.json',  encoding='utf-16').read())['data']['translations']
ZN = {}
for data in alldata:
    qid = data['questionId']
    title = data['title']
    ZN[qid] = title
    # print(f'|{qid}|{title}|')

alldata = json.loads(open('LeetCodeProblems.json',  encoding='utf-16').read())['stat_status_pairs']
leetProb = 'https://leetcode-cn.com/problems/'
M = ('', 'Easy', 'Medium', 'Hard')
newdata = {}
for data in alldata:
    stat = data['stat']
    qid = stat['question_id']
    title = stat['question__title']
    zntitle = ZN.get(str(qid), '')
    if qid in likes: zntitle += '⭐'
    url = leetProb + stat['question__title_slug']
    fid = stat['frontend_question_id']
    level = M[data['difficulty']['level']]
    # print(f'|{fid}|[{title}]({url})|[Cpp]()|{level}|')
    newdata[fid] = (fid, zntitle, title, url, level)

md = f"""
| # | Title | Solution | Difficulty |
|---| ----- | -------- | ---------- |"""


OJ = path.Path('../OJ')
fs = OJ.dirs()
# print(md)
def translate(f: str):
    if f.startswith('lcp'): return f.replace('lcp', 'LCP ')
    if f.startswith('lcci'): return f.replace('lcci', '面试题 ')
    if f.startswith('leet'): return str(int(f.replace('leet', '')))
    if f.startswith('lcof'): 
        f = f.replace('lcof', '剑指 Offer ')
        f = f.replace('_II', ' - II')
        return f
    return ''

Ext = {
    '.cpp': 'C++',
    '.py': 'Python',
    '.go': 'Go',
    '.java': 'Java',
    '.ts': 'Typescript',
    '.rs': 'Rust',
    '.sh': 'Shell',
}

def modify (f: path.Path):
    f = str(f.relpath())
    f = f.replace('\\', '/')
    f = f.replace('../', '')
    f = f.replace(' ', '&#32;')
    return f 

error_indictators = ('TLE', 'junk')
def fetch_sols(fdir):
    sols_links = []
    for ext, lang in Ext.items():
        sols = fdir.glob('**' + ext) + fdir.glob('**/**' + ext)
        ok = lambda f: not any(e in f for e in error_indictators)
        sols = [f for f in sols if ok(f)]
        sols = [modify(f) for f in sols][:3]
        sols_links += [ f'[{lang}]({sol})' for sol in sols ]
    return ', '.join(sols_links)


def printSols(fdirs):
    for f in fdirs:
        sols = fetch_sols(f)
        f = translate(f.basename())
        if not f: continue 
        if f not in newdata: f = f + ' - I'
        if f not in newdata: continue
        (fid, zntitle, title, url, level) = newdata[f]
        print(f'|{fid}|[{zntitle}]({url})|{sols}|{level}|')

print('# LeetCode Solutions')

print('\n## LeetCode\n' + md)
leets = OJ.glob('leet**')
leets.sort(key=lambda f: int(f.basename().replace('leet', '')))
printSols(leets)

print('\n## LCCI\n' + md)
leets = OJ.glob('lcci**')
printSols(leets)

print('\n## LCP\n' + md)
leets = OJ.glob('lcp**')
printSols(leets)


import re 
md = f"""
| # | Title | Solution | Tags |
|---| ----- | -------- | ---------- |"""


print('\n## SJTU\n' + md)
fdirs = OJ.glob('sjtu**')

Map = {
    'sjtu': ('SJTU', 'https://acm.sjtu.edu.cn/OnlineJudge/problem/'),
    'poj': ('POJ', 'http://poj.org/problem?id='),
}
sjtu = 'sjtu'
for fdir in fdirs:
    sols = fetch_sols(fdir)
    f = fdir.glob('**.cpp') [0]
    cont = re.findall(r"/\*\s*(.*?)\s*\*/", f.text(), re.S)
    if cont: cont = cont[0]
    else: cont = ''
    if '1593' in f:
        cont = cont.replace('    ', '&nbsp;&nbsp;&nbsp;&nbsp;')
    cont = re.sub('\n\s*', '<br>', cont)
    f = fdir.basename()
    name, url = Map[sjtu]
    fid = f.replace(sjtu, '')
    url += fid
    print(f'|{fid}|[{f}]({url})|{sols}|<pre>{cont}</pre>|')





md = f"""
| Title | Solution |
| ----- | -------- |"""
print('\n## Codility\n' + md)

codility = OJ / 'codility'
fs = codility.files()
error_codility = ('TLE', 'cases', 'codility')
for f in fs:
    if any(e in f.stem for e in error_codility): continue 
    title = f.stem 
    ext = f.ext 
    sol = modify(f)
    lang = Ext[ext]
    print(f'|{title}|[{lang}]({sol})|')