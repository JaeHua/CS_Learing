import requests
from bs4 import BeautifulSoup
#设定一个大的页数
page_num = 50
cnt = 1
#读取不同的页数
for i in range(1,page_num+1):

    #目标网址
    url = "http://bang.dangdang.com/books/fivestars/1-" + str(i)
    #模拟浏览器
    headers = {
        "User-Agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.188"
    }
    response = requests.get(url,headers=headers)
    if response.ok:

        content = response.text
        #指定解析器
        soup = BeautifulSoup(content,"html.parser")
        #获取指定的信息
        all_names = soup.find_all("div",attrs={"class" : "name"})

        for name in all_names:
            if(name.find("a").string == None):
                continue
            #不换行
            print( str(cnt) + ":",end="")
            #只打印被标签包围的文字
            print(name.find("a").string)
            with open("books.txt",'a',encoding='utf-8') as f:
                f.write(name.find("a").string.encode('utf-8').decode('utf-8')+ '\n')
            cnt += 1
    else:
        print("请求失败")