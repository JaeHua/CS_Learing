import requests
import re

import os

filename = 'photo\\'

if not os.path.exists(filename):
    os.mkdir(filename)
headers = {
'Cookie':'__yjs_duid=1_d5847047ac3493e403ed565cc5213c271690892737561; Hm_lvt_0f461eb489c245a31c209d36e41fcc0f=1690892738; Hm_lpvt_0f461eb489c245a31c209d36e41fcc0f=1690892738; Hm_lvt_c59f2e992a863c2744e1ba985abaea6c=1690892751; Hm_lpvt_c59f2e992a863c2744e1ba985abaea6c=1690892751',
'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.188'
}
for cnt in range(1,26):
    if(cnt==1):
        url = "https://pic.netbian.com/index.html"
    else:
        url = "https://pic.netbian.com/index_"+str(cnt)+".html"
    # #发送请求
    resp = requests.get(url,headers=headers)
        #自动识别编码
    print(resp)
    resp.encoding = resp.apparent_encoding
    # print(resp.text)
    html_data = re.findall(r'<li><a href="(.*?)" .*? target="_blank">.*?</li>',resp.text)
    # print(html_data)
    for link  in html_data:
        if 'javascript:;'not in link and 'vip' not in link :
            if 'https://pic.netbian.com' not in link:
                link_url = f'https://pic.netbian.com' +link
                # print(link_url)
            else:
                link_url = link
                # print(link_url)
            photo_data = requests.get(url = link_url,headers=headers)
            photo_data.encoding = photo_data.apparent_encoding
            # print(photo_data.text)
            #href = ""一定记得是空
            photos = re.search(r'<img src="(?P<url>.*?)"alt="(?P<alt>.*?)">',photo_data.text)
            print(photos.groupdict()['url'])  # 图片链接
            print(photos.groupdict()['alt'])
            # photo_link = "https://pic.netbian.com" + photos
            # title =
            # target = requests.get(url=photo_link,headers=headers).content
            # with open(filename + title + '.jpg', mode='wb') as f:
            #     f.write(target)
            # print(photo_link, title)
resp.close()