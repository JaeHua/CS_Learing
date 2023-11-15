import requests
import re
import os
filename = 'photo\\'
if not os.path.exists(filename):
    os.mkdir(filename)
headers = {
'Cookie':
'PHPSESSID=cga16ni5l2g0qr24ol46b76q34; Hm_lvt_fe338b12aba190ae800147b6d1d0d309=1690943562; Hm_lpvt_fe338b12aba190ae800147b6d1d0d309=1690943578',
'User-Agent':
'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.188'
}
cnt = 1
for i in range(1,70):
     url = f"https://www.toopic.cn/4kbz/?&page={i}"
     resp = requests.get(url,headers=headers)
     resp.encoding = resp.apparent_encoding
     page_content = resp.text
     #注意空格
     html_data = re.findall(r'<a href="(.+?)" target="_blank" class="pic"',page_content)

     for link in html_data:
          link_url =  "https://www.toopic.cn/" + link
          photo_data = requests.get(link_url,headers=headers)
          photos = re.search(r'<img alt="(?P<alt>.*?)" src="(?P<ur>.*?)>',photo_data.text)
          uurr = photos.groupdict()['ur'].strip("\" /")  # 图片链接
          photo_link = "https://www.toopic.cn/" + uurr
          # print(photo_link)
          titlee = (photos.groupdict()['alt'])
          target = requests.get(photo_link,headers=headers).content
          if 'jpg' in photo_link:
               with open(filename + titlee + '.jpg', mode='wb') as f:
                   f.write(target)

               print(str(cnt) + photo_link, titlee)
               cnt += 1
          elif 'png' in photo_link:
               with open(filename + titlee + '.png', mode='wb') as f:
                   f.write(target)

               print(str(cnt)+photo_link, titlee)
               cnt += 1
resp.close()