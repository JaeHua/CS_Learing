package OOTEXT01;

public class OOText02{
    public static void main(String[]args){

        User u=new User();
        System.out.println(u.name);
        System.out.println(u.num);
        System.out.println(u.addr);
        u.num=10;
        u.name="jack";
        u.addr=new Address();
        System.out.println(u.num);
        System.out.println(u.name);
        System.out.println(u.addr);

        u.addr.city="北京";
        u.addr.street="朝阳";
        u.addr.zipcode="5466551";
        System.out.println(u.name + "居住在哪个城市:"+u.addr.city);
        System.out.println(u.name + "居住在哪个街道:"+u.addr.street);
        System.out.println(u.name + "邮编:"+u.addr.zipcode);


    }


}