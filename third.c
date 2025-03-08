#include<stdio.h>
int main()
{
    char arr[5];
    int i;
    for(i=0;i<4;i++)
    {
        
        scanf("%c",&arr[i]);
    }
    printf("your array is : \n");
    for(int i=0;i<5;i++)
    {
        printf("%c",arr[i]);
    }  

}