import java.util.*;
class ds2{
public static void main(String args[])
{
  System.out.println("enter the marks of the student : ");
  Scanner sc = new Scanner(System.in);
  int marks =sc.nextInt();
  if (marks > 90 )
 {
   System.out.println("excellent");
 }
 else if(marks > 80)
 {
  System.out.println("good");
 }
  else if(marks > 70)
 {
  System.out.println("fair");
 }
  else if(marks > 60)
 {
  System.out.println("meets expectations");
 }
else{
  System.out.println("below par");
 }
}
}