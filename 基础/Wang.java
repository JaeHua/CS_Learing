public class Wang {
    public static void main(String[] args){ 
    
     MyClass  y1 = new MyClass(45);
      MyClass  y2 = new MyClass(35);
     System.out.println(y1.x);
     System.out.println(y2.x);
    }
 }
 
 class MyClass {
    //static int x;共用了！！！！！！
     int x;
   MyClass(int i ) {
     x = i;
   }
 }