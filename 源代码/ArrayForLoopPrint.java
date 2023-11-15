import java.util.Scanner;
public class ArrayForLoopPrint {
    public static void main(String[]args){
        System.out.println("Use the for loop to print the value of array");
        int a[]={1,2,3,4,5,6,7,8,9,10};
        for(int number:a){

            System.out.print(number);
            System.out.print(",");
        } 
        System.out.println("请输入需要的数字个数:");

        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        System.out.println("请输入这"+n+"个数:");
        Scanner sc = new Scanner(System.in);
        int b[]=new int[n];
        for(int i=0;i<b.length;i++){
            b[i]=sc.nextInt();
            System.out.print("<--"+b[i]+"-->");
        }
        s.close();
        sc.close();
    }


}
