#include <stdio.h>
#include <stdlib.h>
void swap(int *p1,int *p2);//这是一个简单xyz从大到小的排序代码
/*int main()
{
   int name[3];
   int i=0,j=0;
   printf("please enter x y z");
   for(;i<3;i++)
   {
       scanf("%d",&name[i]);
   }
   for(i=0;i<3;i++)
   {
       for(j=i+1;j<3;j++)
       {
           if(name[i]<name[j])
           {
               swap(&name[i],&name[j]);
           }
       }
   }
    for(i=0;i<3;i++)
   {
       printf("%d",name[i]);
   }
    return 0;
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
*/
#define n 5
int main()
{
    int a[n];
    int i=0;
    double x0,p=0.0;
    printf("请输入系数");
    for(;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("请输入x0");
    scanf("%lf",&x0);
    while(i>=0)
    {
        p=p*x0+a[i];
        i--;
    }
    printf("%f",p);
}








