    //理解方法调用顺序

public class Method02 {
    public static void sum(int a ,int b){
        int c=a+b;
        System.out.println(a+"+"+b+ "=" +c);
        Method02.doSome();
    }
    public static void main(String[] args){
        Method02.sum(154,465);
        sum(123,466);
        System.out.println("幸会幸会");

        A.doOther();
    }
    public static void doSome(){
        System.out.println("Hello World");
    }
}
    //开发中不建议这么写
class A{
    public static void doOther(){
        System.out.println("execute！");
    }

}
