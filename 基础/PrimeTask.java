public class PrimeTask {
        public static void main(String[]args){
            System.out.println("欢迎使用本素数查找系统");
            System.out.println("请输入您所需要查找的数据范围");
            java.util.Scanner s = new java.util.Scanner(System.in);
            int beginNumber =s.nextInt(); 
            int endinNumber =s.nextInt(); 
            System.out.println("请输入您需要的换行素数个数");
            int numble=s.nextInt();
            int count =0;
            int i=0;int j=0;
            int isPrime=1;
            int cnt = 0;
            int alternative ;
            alternative = beginNumber;
            System.out.println("***********************************************************************************");
            if(beginNumber==1){
                beginNumber=2;
            }
            for(i=beginNumber;i<=endinNumber;i++){
                for(j=2;j<i;j++){
                    if(i%j==0){
                        isPrime=0;
                        break;
                    }
                    isPrime=1;
                    }
                    if(isPrime==1){
                        System.out.print(i+" ");
                        count++;
                        cnt++;
                        if(count==numble){
                            System.out.println();
                            count=0;
                        }
                }
            
            }
             System.out.println("");
            System.out.println("***********************************************************************************");
            System.out.println("从"+alternative+"到"+endinNumber+"共有"+cnt+"个素数");
            


        }
}
