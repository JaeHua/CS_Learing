public class SwitchUse {
    public  static void main(String[] args){
        java.util.Scanner s =new java.util.Scanner(System.in);
        System.out.println("欢迎使用本成绩判定系统!(*.*)");
        System.out.println("请输入你的成绩");
        int userGrade = (s.nextInt()/10);
        switch(userGrade){
            case 10:
            case 9:
            System.out.println("您的成绩等级为A");
            break;
            case 8:
            case 7:
            case 6:
            System.out.println("您的成绩等级为B");
            break;
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
            System.out.println("您的成绩等级为C");
            break;
            case 0:
            System.out.println("您的成绩等级过低，有被退学风险");
            break;
            default :
            System.out.println("对不起，您的成绩咋回事!");

            s.close();


        }

    }
    
}
