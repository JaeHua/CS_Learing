import tkinter as tk
import subprocess #进程
#下载事件
def download():
    link = f'you-get -o video {key_word.get()}'
    subprocess.run(link,shell=True)
def clean():
    e.delete(0,'end')

root = tk.Tk()

root.title('视频下载小程序')

#界面大小

root.geometry("350x50+150+150")

txt = tk.Label(text = "输入下载网址:",font=50)



#设置位置

txt.grid(row = 0,column=0)
key_word = tk.StringVar()
#设置空白框

e = tk.Entry(root,textvariable = key_word)

e.grid(row = 0,column=1)

#设置按钮

bt = tk.Button(text = "下载",command=download)

bt.grid(row=0,column=3)

bt = tk.Button(text = "清空")

bt.grid(row=0,column=4)
#刷新页面
root.mainloop()