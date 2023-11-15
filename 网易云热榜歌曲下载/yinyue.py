import requests
import  re
import os
d
filename = 'music\\'

if not os.path.exists(filename):
    os.mkdir(filename)
#指定的爬取网站
url = "https://music.163.com/discover/toplist?id=3778678"

headers = {
'Cookie':'NMTID=00Ocki-JrUWGjSiDkXGuabImypagnkAAAGJpeXzNA; JSESSIONID-WYYY=b%5C94BjH1qzM2dXQY5TzPoOYP5KxYhA2wPKo5b4KMT3BueSgpjZ0dChF2C5o%2BynauEhlY%2FPQ1E%2Bmf%2FWOxTQQt9AJKJsZiU9%2FQn2J5XRl7V3Pwwf8r%5Cymos4rqs0WSPFx9wdO%2BJIq9J7J6wdkiVnZIH1fUatUzpRDCjOzdQjsbqnDi01RH%3A1690707257480; _iuqxldmzr_=32; _ntes_nnid=9ad6e143e241fe8c281ed7ea60da43b6,1690705457496; _ntes_nuid=9ad6e143e241fe8c281ed7ea60da43b6; WEVNSM=1.0.0; WNMCID=swnrgy.1690705459172.01.0; WM_NI=6mHR6I30tDYoW8HBXGCLBTglR4AT44DGyXhMV%2FxIdOBTQFOhwKZcU6HPltVwqeb5QBGB64DHboL6pxa6IE3PSMzOLhSk0Rlol5%2BP6%2B2hV8ZHq8RjLrYV97FEv3BSvE%2FtRW0%3D; WM_NIKE=9ca17ae2e6ffcda170e2e6eea9d95cb7b7aad8c174f3a88ea7d45a839a8b87c474fcf0b797c668978e8a8dbc2af0fea7c3b92af6b388b3b543f1f0bca5dc6595e888a3db4d81948eb5e66892ec8fb5b7408899b7b9eb4796f1b8aae745828c9fa7ce64b5959684d83e8c90a495d57db3bbaed6d44a859efad5c744a2b184d7f374a3ea87a6b25c9193b6b0cf6491b500b3ef65b0ebe5b1b521f2b89ad9d944b3e89e8bcf7a9b8af7d8c54fb6ed8eb4f54fedac9eb8b337e2a3; WM_TID=%2FOwsV4bYZuNEAEAURVaFkoh37GlVAUxp; ntes_utid=tid._.y%252B05lrRfEHZBAhQBRFbVg4xn%252BTwBbR%252B7._.0; sDeviceId=YD-cM8qABGLfG9BAgRAQUPF0tlm%2FGlQPTBA'
,'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.188'
}

response  = requests.get(url,headers=headers)



html_data = re.findall('<a href="/song\?id=(\d+)">(.*?)</a>',response.text)

for num_id,title in html_data:
    #接口
    music_url = f'https://music.163.com/song/media/outer/url?id={num_id}'
    #对于音乐播放器地址发送请求，获取二进制数据内容
    music_content = requests.get(url=music_url,headers= headers).content
    with open(filename+title +'.mp3',mode='wb')as f:
        f.write(music_content)
    print(num_id,title)
