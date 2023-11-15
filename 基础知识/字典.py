#一个简单的字典
alien_0 = {'color':'green','points':5}
print(alien_0['color'])
print(alien_0['points'])

#添加键值对
alien_0['new_key_gender'] = 'female'
print(alien_0)

#删除键值对
del alien_0['points']
print(alien_0)

#遍历字典
#-遍历所有键值对
user_0 = {
    'username' : 'efermi',
    'first' : 'enrico',
    'last':'fermi',
}
for key,value in user_0.items():
    print("Key:"+key)
    print("Value:"+value)

#-遍历所有键
'''keys()方法返回的是一个列表，并非只能用于遍历'''
for key in user_0.keys():
    print(key)

#-遍历所有值
for value in user_0.values():
    print(value)
'''如果想去重，使用 set 函数'''
print(set(user_0.values()))

#嵌套
#-字典列表
alien_1 = {'color':'green','points':6}
alien_2 = {'color':'red','points':7}
alien_3 = {'color':'black','points':8}

aliens = [alien_1,alien_2,alien_3]
print(aliens)
for alien in aliens:
    print(alien)

#在字典里存储列表
'''每当需要在字典中将一个键关联多个值时，都可以在字典里嵌套一个列表'''
favorite_languages = {
    'jen' :['python','ruby'],
    'sarah':['c'],
    'edward':['ruby','go'],
    'phil':['python','haskell']
}

for name,languages in favorite_languages.items():
    print(name.title() + "'s favorite languages are :")
    for language in languages:
        print("\t" + language.title())