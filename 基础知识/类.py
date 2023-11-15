#一个简单类实例
class Dog():
    '''一次模拟小狗的简单尝试'''
    def __init__(self,name,age):
        '''初始化属性name和age'''
        self.name = name
        self.age = age
    def sit(self):
        print(self.name.title() + ' is now sitting')

    def roll_over(self):
        '''to imitate how a puppy rolled over when it is called'''
        print(self.name.title() + ' rolled over')
'''the method 'init' has a line before and after it. it was aimed to avoid 
controdiction with common method'''

#根据类创建实例
my_dog = Dog('wille',6)
print("my dog's name is  " + my_dog.name.title() +'.')
print("my dog is  " + str(my_dog.age) +'.')
my_dog.sit()
my_dog.roll_over()

#继承
'''编写类的时候并非都要从空白开始。一个类继承另外一个类的时候，将自动获得另一个类的所有属性和方法'''

#重写父类的方法
'''对于父类的方法，只要它不符合子类模拟的实物行为，都可以对其进行重写，方法同名就行'''