import requests

url ="https://fanyi.baidu.com/sug"
s = input("输入您要翻译的词:\n")
dat = {
    "kw":s
}
#发送post请求
resp = requests.post(url,data = dat)
#解析
print(resp.json())