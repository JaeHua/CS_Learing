public class enter{
    public static void main(String[] args){
        java.util.Scanner s = new java.util.Scanner(System.in);
        System.out.print("请输入数据");
        String userInPut =s.next();
        System.out.println("你输入的是"+userInPut);
        s.close();
    }
}
