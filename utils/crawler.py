import os, requests, requests_cache, re

class Leetcode:
    LEETCODE_URL = 'https://leetcode-cn.com'
    LEETCODE_LIST_URL = 'https://leetcode-cn.com/api/problems/all/'
    LEETCODE_QUESTIONS = "https://leetcode-cn.com/list/api/questions"
    LEETCODE_GRAPHQL = 'https://leetcode-cn.com/graphql'
    def __init__(self):
        self.cookies = os.environ['LEETCODE_COOKIE']
        self.headers = {
            "accept": "*/*",
            "accept-encoding": "gzip, deflate, br",
            "accept-language": "zh-CN,zh;q=0.9,la;q=0.8,de;q=0.7,en;q=0.6,zh-TW;q=0.5",
            "cache-control": "no-cache",
            "content-type": "application/json",
            "cookie": self.cookies,
            "dnt": "1",
            "pragma": "no-cache",
            "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.72 Safari/537.36",
            "x-requested-with": "XMLHttpRequest",
            }
        self.cached_solved_quest = {}

    def get_solved_list(self):
        with requests_cache.disabled():
            # print("solved_list: ", requests.get(Leetcode.LEETCODE_LIST_URL, headers=self.headers).json())
            # solv_list = requests.get(Leetcode.LEETCODE_LIST_URL, headers=self.headers).json()
            return [{
                "question_slug": v['stat']['question__title_slug'],
                "question_id": v['stat']['frontend_question_id'], # 用页面上显示的id
                "question_title": v['stat']['question__title'],
                "question_difficulty": v['difficulty']['level']
                } for v in
                    requests.get(Leetcode.LEETCODE_LIST_URL, headers=self.headers).json()['stat_status_pairs']
                if v['status'] == 'ac'
            ]

    def get_source(self, url): # /submissions/detail/14313499/
        req_url = self.LEETCODE_URL + url
        try:
            src = re.search('submissionCode: \'(.*)\',', requests.get(req_url, headers=self.headers).text).group(1)
            return src.encode('cp1252', 'backslashreplace').decode('unicode-escape')
        except AttributeError:
            pass

    def get_question_content(self, question_slug): # /problems/number-of-enclaves/
        data = '{"operationName":"questionData","variables":{"titleSlug":"%s"},"query":"query questionData($titleSlug: String!) {\\n  question(titleSlug: $titleSlug) {\\n    questionId\\n    questionFrontendId\\n    boundTopicId\\n    title\\n    titleSlug\\n    content\\n    translatedTitle\\n    translatedContent\\n    isPaidOnly\\n    difficulty\\n    likes\\n    dislikes\\n    isLiked\\n    similarQuestions\\n    contributors {\\n      username\\n      profileUrl\\n      avatarUrl\\n      __typename\\n    }\\n    langToValidPlayground\\n    topicTags {\\n      name\\n      slug\\n      translatedName\\n      __typename\\n    }\\n    companyTagStats\\n    codeSnippets {\\n      lang\\n      langSlug\\n      code\\n      __typename\\n    }\\n    stats\\n    hints\\n    solution {\\n      id\\n      canSeeDetail\\n      __typename\\n    }\\n    status\\n    sampleTestCase\\n    metaData\\n    judgerAvailable\\n    judgeType\\n    mysqlSchemas\\n    enableRunCode\\n    enableTestMode\\n    envInfo\\n    __typename\\n  }\\n}\\n"}' % question_slug
        question_content = requests.post(self.LEETCODE_GRAPHQL,
                                         headers=self.headers,
                                         data=data).json()['data']['question']
        return question_content

    def get_problems_translation(self):
        data = '{\"operationName\":\"getQuestionTranslation\",\"variables\":{},\"query\":\"query getQuestionTranslation($lang: String) {\\n  translations: allAppliedQuestionTranslations(lang: $lang) {\\n    title\\n    questionId\\n    __typename\\n  }\\n}\\n\"}'
        translations = requests.get(Leetcode.LEETCODE_GRAPHQL, headers=self.headers, data=data).json()['data']['translations']
        return { entry['questionId']: entry['title'] for entry in translations}
        
    def get_problems(self):
        return   requests.get(Leetcode.LEETCODE_LIST_URL, headers=self.headers).json()['stat_status_pairs']
        
    def get_likes(self):
        with requests_cache.disabled():
            favors = requests.get(Leetcode.LEETCODE_QUESTIONS, headers=self.headers).json()
            favors = favors['favorites']
            favors = favors['public_favorites'] + favors['private_favorites']
            return set( Q['id']  for favor in favors for Q in favor['questions'] )
        
if __name__ == '__main__':
    requests_cache.install_cache('leetcode')
    lc = Leetcode()
    print(lc.get_likes())
