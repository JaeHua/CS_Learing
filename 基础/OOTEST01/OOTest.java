package OOTEST01;
public class OOTest {
    //先创造人对象
    //然后创造房子对象
    //让房子有主人
    public static void main(String[]args){
    Owner zhangsan = new Owner();
    zhangsan.name="张三";
   House fangzi = new House();
    fangzi.zhuRen = zhangsan;
    zhangsan.id=12356;
    zhangsan.sex=true;
    fangzi.area=152.36;
        System.out.println(fangzi.zhuRen.name);
        System.out.println(fangzi.zhuRen.id);
        System.out.println(fangzi.zhuRen.sex);
        System.out.println(fangzi.area);
        Owner lisi = new Owner();
        lisi.name ="李四"; 
        fangzi.zhuRen=lisi;
        System.out.println(fangzi.zhuRen.name);
        

}
}   