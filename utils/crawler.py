import os, requests, requests_cache, re

class Leetcode:
    LEETCODE_URL = 'https://leetcode-cn.com'
    LEETCODE_LIST_URL = 'https://leetcode-cn.com/api/problems/all/'
    LEETCODE_QUESTIONS = "https://leetcode-cn.com/list/api/questions"
    LEETCODE_GRAPHQL = 'https://leetcode-cn.com/graphql'
    def __init__(self):
        self.cookies = os.environ['LEETCODE_COOKIE']
        self.headers = {
            "accept": "application/json, text/javascript, */*; q=0.01",
            "accept-encoding": "gzip, deflate, br",
            "accept-language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
            # "cache-control": "no-cache",
            "content-type": "application/json",
            "sec-ch-ua": "\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"101\", \"Microsoft Edge\";v=\"101\"",
            "sec-ch-ua-mobile": "?0",
            "sec-ch-ua-platform": "\"Windows\"",
            "sec-fetch-dest": "empty",
            "sec-fetch-mode": "cors",
            "sec-fetch-site": "same-origin",
            "x-requested-with": "XMLHttpRequest",
            # "cookie": self.cookies,
            "cookie": "aliyungf_tc=99c9b9f75027271f724228305bdb920ceeb66ca16c034236b5f38a69450e311e; NEW_PROBLEMLIST_PAGE=1; csrftoken=CZ6YOATl633tJCcCjb5SiyTKQFoDF658uNjA9iDKWcp56TYDUNyMgiGaAZNTxNms; _bl_uid=OXlX52y1y18nC5n8qj15x3tjyOpn; LEETCODE_SESSION=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJuZXh0X2FmdGVyX29hdXRoIjoiL3Byb2JsZW1zZXQvYWxnb3JpdGhtcy8iLCJfYXV0aF91c2VyX2lkIjoiMzYwOTAxIiwiX2F1dGhfdXNlcl9iYWNrZW5kIjoiZGphbmdvLmNvbnRyaWIuYXV0aC5iYWNrZW5kcy5Nb2RlbEJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiJkY2RkNjEwZThmMzAwOTQ2NjZmMTEzNzg2NWVhOTUxODAzOWY5MDgxMDFlMTVmMTUwNzY0ZDI4N2FiNDMwYmMyIiwiaWQiOjM2MDkwMSwiZW1haWwiOiJvbmVmb3J3YXJkQDEyNi5jb20iLCJ1c2VybmFtZSI6Im9uZWZvcndhcmQiLCJ1c2VyX3NsdWciOiJvbmVmb3J3YXJkIiwiYXZhdGFyIjoiaHR0cHM6Ly9hc3NldHMubGVldGNvZGUuY24vYWxpeXVuLWxjLXVwbG9hZC91c2Vycy9vbmVmb3J3YXJkL2F2YXRhcl8xNTQ5NDUxNjE5LnBuZyIsInBob25lX3ZlcmlmaWVkIjp0cnVlLCJfdGltZXN0YW1wIjoxNjUyMDk2NTk2LjU5MDg5MjgsImV4cGlyZWRfdGltZV8iOjE2NTQ2Mjg0MDAsInZlcnNpb25fa2V5XyI6MCwibGF0ZXN0X3RpbWVzdGFtcF8iOjE2NTIxMDg4NzF9.TpHax8C5AXGT66Dy4XGHAGa9fI2PbED3fHB8zBuAEts",
            # "dnt": "1",
            # "pragma": "no-cache",
            # "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.72 Safari/537.36",

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
