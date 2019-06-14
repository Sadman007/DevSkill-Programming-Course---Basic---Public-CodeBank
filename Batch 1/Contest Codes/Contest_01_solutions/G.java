import java.util.Scanner;

import java.math.*;


public class Main{

    public static void main(String[] args) {

        Scanner obj=new Scanner(System.in);
        String s1,s2;

        for(int i=0;i<10;i++)
        {
        s1=obj.next();
        s2=obj.next();

        BigInteger a=new BigInteger(s1);
        BigInteger b=new BigInteger(s2);

        BigInteger c=a.subtract(b);

        BigInteger divisor=new BigInteger("2");

        BigInteger div=c.divide(divisor);

        System.out.println(b.add(div));
        System.out.println(div);

    }

}

}
