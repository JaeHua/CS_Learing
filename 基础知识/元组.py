#元组
'''元组是不能修改改变的列表'''

#元组的定义
dimensions = (200,50)
print(dimensions[0])
print(dimensions[1])

# 禁止修改，会抛出异常：TypeError: 'tuple' object does not support item assignment。dimensions[0] = 250

#元组的遍历
for dimension in dimensions:
    print(dimension)

#元组变量整体可以进行赋值，但是不能修改元素
dimensions = (100,200)
print(dimensions)



