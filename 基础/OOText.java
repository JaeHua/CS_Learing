//对象的创建和使用
public class    iOOText {
    String addr;
    int age;
    //以上为属性，是状态信息
    //成员变量未初始化是数字-->0,字符型-->null,布尔型-->false
    public static void main(String[] args){
        //通过一个类可以实例化N个对象
        //new运算符的作用是创建对象，在JVM堆内存当中开辟新的内存空间
        //方法区内存：在类加载的时候，class字节码代码片段被加载到该内存空间中。
        //栈内存（局部变量）：方法代码片段执行的时候，会给该方法分配内存空间，在栈内存中堆栈
        //堆内存：new的对象在堆内存中存储,成员变量中的实例变量储存于此
        OOText s = new OOText();
      //s是一个引用，同时是一个局部变量
        s.age = 10;//靠引用变量修改
        String stuAdrr = s.addr;  
        
         stuAdrr = "北京";
        System.out.println("学生的年龄是"+s.age);
        System.out.println("学生的地址是"+stuAdrr);
        //通过对象才能访问实例变量，不能直接通过类名访问

    }
}
