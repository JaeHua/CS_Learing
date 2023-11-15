public class TestReturn {
    public static void main(String[]args){
          int count =0;
        for (int i=1;i<=5000;i++){ 
            if(i==5000){
                return;
                //return结束的是整个main方法
                //break比较弱，只能结束for循环
                
            }
            System.out.print("i -->"+i);
            count++;
            if(count==5){
                System.out.println("");
                count=0;
            }
        }
        System.out.println("Hello world!");
    }


    
}
