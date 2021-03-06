import os, requests, requests_cache, re

class Leetcode:
    LEETCODE_URL = 'https://leetcode-cn.com'
    LEETCODE_LIST_URL = 'https://leetcode-cn.com/api/problems/all/'
    LEETCODE_QUESTIONS = "https://leetcode.cn/list/api/questions"
    LEETCODE_GRAPHQL = 'https://leetcode-cn.com/graphql'
    def __init__(self):
        self.cookies = os.environ['LEETCODE_COOKIE']
        self.headers = {
            "accept": "application/json, text/javascript, */*; q=0.01",
            "accept-encoding": "gzip, deflate, br",
            "accept-language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
            "content-type": "application/json",
            "sec-ch-ua": "\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"101\", \"Microsoft Edge\";v=\"101\"",
            "sec-ch-ua-mobile": "?0",
            "sec-ch-ua-platform": "\"Windows\"",
            "sec-fetch-dest": "empty",
            "sec-fetch-mode": "cors",
            "sec-fetch-site": "same-origin",
            "x-requested-with": "XMLHttpRequest",
            "cookie": self.cookies,
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
        with requests_cache.disabled():
            data = '{\"operationName\":\"getQuestionTranslation\",\"variables\":{},\"query\":\"query getQuestionTranslation($lang: String) {\\n  translations: allAppliedQuestionTranslations(lang: $lang) {\\n    title\\n    questionId\\n    __typename\\n  }\\n}\\n\"}'
            translations = requests.get(Leetcode.LEETCODE_GRAPHQL, headers=self.headers, data=data).json()['data']['translations']
            return { entry['questionId']: entry['title'] for entry in translations}
        
    def get_problems(self):
        with requests_cache.disabled():
            return  requests.get(Leetcode.LEETCODE_LIST_URL, headers=self.headers).json()['stat_status_pairs']
        
    def get_likes(self):
        with requests_cache.disabled():
            favors = requests.get(Leetcode.LEETCODE_QUESTIONS, headers=self.headers).json()
            favors = favors['favorites']
            favors = favors['public_favorites'] + favors['private_favorites']
            return set( Q['id']  for favor in favors for Q in favor['questions'] )
        
if __name__ == '__main__':
    requests_cache.install_cache('leetcode')
    lc = Leetcode()
    # print(lc.get_problems())
    # print(lc.get_problems_translation())
    print(lc.get_likes())
