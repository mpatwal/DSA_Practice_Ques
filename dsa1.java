import java.util.*;
public class dsa1{
public static void main(String args[])
{
 System.out.println("how many numbers you want to check : ");
 Scanner sc = new Scanner(System.in);
 int t;
 t = sc.nextInt();
for(int n=0;n<t;n++)
{
  int num = sc.nextInt();
  if(num % 2 == 0)
{
  System.out.println("even");
}
else
{
System.out.println("not-even");
}
}
}
 }