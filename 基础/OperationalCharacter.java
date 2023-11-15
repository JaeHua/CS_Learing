public class OperationalCharacter {
    //查看两种自增符号的区别
    public static void main(String[]args){
        System.out.println("查看两种自增符号的区别");
        java.util.Scanner s = new java.util.Scanner(System.in);
        int number=s.nextInt();
        System.out.println("打印的数字为"+number);
        System.out.println("number++打印的数字为"+(number++)+"<--这一个是先打印再自增");
        System.out.println("++numbe打印的数字为"+(++number)+"<--这一个是先自增再打印");
        int a = 10;
        int b = 20;
        int c = 0;
        c = a + b;
        System.out.println("c = a + b = " + c );
        System.out.println(" a = " + a );
        System.out.println("b =  " + b );
        c += a ;
        System.out.println("c += a  = " + c );
        c -= a ;
        System.out.println("c -= a = " + c );
        c *= a ;
        System.out.println("c *= a = " + c );
        a = 10;
        c = 15;
        c /= a ;
        System.out.println("c /= a = " + c );
        a = 10;
        c = 15;
        c %= a ;
        System.out.println("c %= a  = " + c );
        c <<= 2 ;
        System.out.println("c <<= 2 = " + c );
        c >>= 2 ;
        System.out.println("c >>= 2 = " + c );
        c >>= 2 ;
        System.out.println("c >>= 2 = " + c );
        c &= a ;
        System.out.println("c &= a  = " + c );
        c ^= a ;
        System.out.println("c ^= a   = " + c );
        c |= a ;
        System.out.println("c |= a   = " + c );
        s.close();

    }
    


    
}
