#函数的定义
def greet_user():
    '''显示简单的问候语'''
    print("Hello !")
greet_user()

#向函数传递信息
def greet_user(username):
    '''显示简单的问候语'''
    print("Hello " + username+ "!")

#关键字实参
greet_user(username='jack')

#返回值
def get_formatted_name(first_name,last_name):
    '''返回整洁的姓名'''
    full_name = first_name + ' ' + last_name
    return full_name
musician = get_formatted_name('jimi','hendrix')
print(musician)

#让实参变成可选的
'''注意可选的参放在最后面'''
def gett_formatted_name(first_name,last_name,middle_name = ''):
    if middle_name:
        full_name = first_name + ' '+middle_name+ ' ' + last_name
    else:
        full_name = first_name + ' ' + last_name
    return  full_name
musicians = gett_formatted_name('jhon','hooker','lee')
print(musicians)

#返回字典
def build_person(first_name,last_name):
    person = {'first':first_name,'last':last_name}
    return person
person_built = build_person('jimi','buter')
print(person_built)

#禁止函数修改列表
'''fuction_name(list_name[:])'''

#传递任意数量的实参
'''此时的toppings是一个元组'''
def make_pizza(*toppings):
    '''打印顾客的所有配料'''
    for topping in toppings:
        print(topping)
make_pizza('pepperoni','mushrooms')

#接受任意数量的关键字实参
'''user_info传入的是字典'''
def build_profile(first,last,**user_info):
    profile = {}
    profile['first_name'] = first
    profile['last_name'] = last
    for key,value in user_info.items():
        profile[key] = value
    return profile
user_profile = build_profile('albert','eistein',location = 'princetion',field = 'physics')
print(user_profile)

#导入
#-导入模块
'''import pizza'''
#-导入模块中的特定函数
'''from module_name import fuction_name'''
#-使用as起别名
'''from pizza import make_pizza as mp'''
#-导入模块中所有函数
'''from pizza import *'''

