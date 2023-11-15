#导包
import requests
import parsel
import csv
import datetime
#创建csv文件
f = open("热搜.csv",mode = 'a',encoding= 'ANSI',newline='')

#配置文件
now = datetime.datetime.now()
ff = open("热搜.csv",'a')
ff.write(str(now) + '\n')
csv_write = csv.DictWriter(f,fieldnames=['排名:','标题:','热度:'])
#写入表头
csv_write.writeheader()

#请求网址
url = "https://s.weibo.com/top/summary"

headers = {
    #用户信息，常用于判断登陆账号
    'cookie' : 'SUB=_2AkMTmZ4Qf8NxqwFRmP4dy2jnaYt0zwjEieKlxW_LJRMxHRl-yT9vqnw_tRB6OBmw_6jNEnqrF0i-u71EwpX55b6sHbFY; SUBP=0033WrSXqPxfM72-Ws9jqgMF55529P9D9WFDylihxZmXC.bajRIB-vs8; _s_tentry=-; Apache=8787674780988.884.1690636672503; SINAGLOBAL=8787674780988.884.1690636672503; ULV=1690636672513:1:1:1:8787674780988.884.1690636672503',
    #用户代理，浏览器基本标识
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.188'
}

#发送请求
response = requests.get(url = url ,headers = headers)


#转数据类型
selectors = parsel.Selector(response.text)

#第一次提取css选择器，获取所有标签数据内容
"""注意学习怎么提取"""
trs = selectors.css('#pl_top_realtimehot tbody tr')
num = 1
for tr in trs:
        #获取热搜标题
        title = tr.css('.td-02 a::text').get()
        #获取热搜热度
        hot  = tr.css('.td-02 span::text').get()
        #创建字典储存数据
        dir = {
            "排名:" : num,
            "标题:" : title,
            "热度:" : hot
        }
        #保存数据
        print(dir)
        csv_write.writerow(dir)
        num += 1

