import requests
import re

cnt = 1

for num in range(1,1000):
    url = f"https://bbs.hupu.com/502-hot-"+str(num)

    resp = requests.get(url)

    page_content = resp.text

    #解析数据
    obj = re.compile(r'<li class="bbs-sl-web-post-body">.*?<div class="post-title">.*?<a.*?>(?P<content>.*?)</a>',re.S)

    ret = obj.finditer(page_content)
    print(ret)
    # for it in ret:
    #     print(it.group("content"))
    #     f = open('data.txt','a',encoding='utf-8')
    #     f.write(str(cnt)+'：'+it.group("content").encode('utf-8').decode('utf-8')+'\n')
    #     cnt += 1
