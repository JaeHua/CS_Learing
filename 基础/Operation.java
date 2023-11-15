
import java.awt.*;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Transferable;
import java.awt.event.KeyEvent;
import java.util.Scanner;
public class Operation {
    public static void main(String[] args) throws AWTException {
        Scanner s = new Scanner(System.in);
        System.out.println("莫急");
        String str = s.next();
        System.out.println("100");
        int code = s.nextInt();
        System.out.println("100");
        int time = s.nextInt();
        Robot robot = new Robot();
        int cnt=5;
        for(int i=1;i<=5;i++){
            System.out.println("轰炸还有"+cnt+"秒开始...");
            robot.delay(1000);
            cnt--;
        }
        Clipboard clip = Toolkit.getDefaultToolkit().getSystemClipboard();
        String[] authors = str.split("[,]");
        for (int j = 0; j < code; j++){
            for (int i = 0; i < authors.length; i++) {
                String str1 = authors[i];
                Transferable text = new StringSelection(str1);
                clip.setContents(text, null);
                robot.keyPress(KeyEvent.VK_CONTROL);
                robot.keyPress(KeyEvent.VK_V);
                robot.keyRelease(KeyEvent.VK_CONTROL);
                robot.delay(time);
                robot.keyPress(KeyEvent.VK_ENTER);
            }
        }
        System.out.println("轰炸完成！");
        System.out.println("\n3秒后自动退出程序...");
        robot.delay(3000);
    }
}