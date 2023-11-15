#if使用简单示例
cars = ['audi','bmw','subaru','toyota']

for car in cars:
    if car == 'bmw':
        print(car.upper())
    else:
        print(car.title())

#条件测试
#-检查是否相等
'''
>>>car = 'audi'
>>>car == 'audi'
true
'''

#检查是否不相等
requested_topping = 'mushrooms'
if requested_topping != 'ahcohol':
    print('fuck!')

#检查特定值位于列表之中
requested_things = ['mushrooms','onions','pineapple']
if 'mushrooms' in requested_things:
    print('mushrooms is in requested_things')

#if  else elif用法
'''
if   [表达式1]:
elif [表达式2]:
else [表达式3]:
'''