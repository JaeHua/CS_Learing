#列表样式
bicycle = ['trek','cannondale','readline','specialized']

#列表打印
print(bicycle)

#采用for循环
for it in bicycle:
    print(it)

#访问列表元素
print(bicycle[0])

#首字母大写
print(bicycle[0].title())

#修改列表元素
bicycle[0] = "Alex"
print(bicycle)

#列表中添加元素
#-列表末尾添加
bicycle.append("addi")
print(bicycle)

#-插入到任何位置
bicycle.insert(1,'insertion')
print(bicycle)

#列表删除元素
#-del删除元素
del bicycle[0]
print(bicycle)

#-pop删除列表末尾的值，并且可以接着使用它
poped_bicycle = bicycle.pop()
print(bicycle)
print(poped_bicycle)

#-pop弹出任何位置元素
frist_owned = bicycle.pop(0)
print("The first bicycle I owned was a " + frist_owned.title() + '.')

#-根据值来删除元素
bicycle.remove('readline');
print(bicycle)

#组织列表
#-sort()进行永久排序
cars = ['bmw','audi','toyota','subaru']
cars.sort()
print(cars)
#-倒着打印
cars.reverse()
print(cars)
#-获取列表长度
print(len(cars))

#操作列表
#-遍历整个列表
magicians = ['alice','david','carolina']
for magician in magicians:
    print(magician)

#创建数值列表
#-使用函数range
'''range(first,number,step)'''
for value in range(1,5,2):
    print(value)
#-数字列表
numbers = list(range(1,10,2));
print(numbers)

squares = []
for value in range(1,11):
    squares.append(value**2)
print(squares)

#-数字列表简单统计
print(min(squares))
print(max(squares))
print(sum(squares))

#列表解析(一行代码就能生成对应列表)
'''使用这种语法，首先指定一个描述性的列表名，然后指定一个左方括号，并定义一个表达式，用于生成要存储到列表中的值
接下来编写一个for循环用来给表达式提供值，再加上右方括号'''
squ = [value**2 for value in range(1,11)]
print(squ)

#切片
'''[开始索引，终止索引（不包含）]'''
players = ['charles','martina','michal','florence','eli']
print(players[0:3])
print(players[:3])
print(players[1:])
print(players[-4:-1])

#复制列表
my_foods = ['pizza','falafel','carrot','cake']
friend_foods = my_foods[:]
print(friend_foods)
'''不同列表对象'''
friend_foods[0] = 'a'
print(my_foods)
'''还是同一个对象'''
fr_foods = my_foods
fr_foods[0] = 'a'
print(my_foods)