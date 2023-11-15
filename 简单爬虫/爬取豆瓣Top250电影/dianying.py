import requests
import parsel
import csv
f = open("Top250电影.csv",mode = 'a',encoding= 'ANSI',newline='')
num = 1
csv_write = csv.DictWriter(f,fieldnames=['排名:','标题:','主演:','评分:'])
#写入表头
csv_write.writeheader()
headers = {
'Cookie':'bid=t6V4uHgbPHY; _pk_id.100001.4cf6=ac96ef25edb4bfa2.1690602680.; __yadk_uid=ezMIocJzjjBeegBKVC6ABmnqumVtjfHS; _pk_ref.100001.4cf6=%5B%22%22%2C%22%22%2C1690688503%2C%22https%3A%2F%2Fcn.bing.com%2F%22%5D; _pk_ses.100001.4cf6=1; ap_v=0,6.0; __utma=30149280.44196322.1690602680.1690602680.1690688504.2; __utmb=30149280.0.10.1690688504; __utmc=30149280; __utmz=30149280.1690688504.2.2.utmcsr=cn.bing.com|utmccn=(referral)|utmcmd=referral|utmcct=/; __utma=223695111.576892031.1690602680.1690602680.1690688504.2; __utmb=223695111.0.10.1690688504; __utmc=223695111; __utmz=223695111.1690688504.2.2.utmcsr=cn.bing.com|utmccn=(referral)|utmcmd=referral|utmcct=/'
,'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.188'
}
for start_num in range(0,250,25):
    url = f'https://movie.douban.com/top250?start={start_num}&filter='
    response = requests.get(url,headers = headers)
    print(start_num)
    content = response.text
    #转数据类型
    selectors = parsel.Selector(content)

    for item in selectors.css('.item'):
        # 定位到单个电影
        movie = item.css('.info')

        # 提取名称
        name = movie.css('.hd .title::text').get()
        # print('电影名称:', name)

        # 提取演员
        actors = movie.css('.bd p::text').re_first(r'主演: (\S+)')
        # print('主演:', actors)

        # 提取评分
        #正则表达式提取第一个元素
        score = movie.css('.rating_num::text').get()
        # print('评分:', score)
        dir = {
            "排名:": num,
            "标题:": name,
            "主演:": actors,
            "评分:":score
        }
        csv_write.writerow(dir)
        num+=1
        print(dir)
        # print('-' * 50)  # 分隔线