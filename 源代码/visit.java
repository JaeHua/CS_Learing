public class visit 
{   
    String name;
    int salary;
    public void  Employee(String Name){
     name = Name;
    }
    public void PrintName (){
        System.out.println("这个人的名字叫"+name);
    }
    public static void main(String[] args){
        System.out.println("请输入一个字符串");
        visit ename = new visit();
        java.util.Scanner s = new java.util.Scanner(System.in);
        String A =s.next();
        ename.Employee(A);
        ename.PrintName();
        s.close();

    }
    
}
