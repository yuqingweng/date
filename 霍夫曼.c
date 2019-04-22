#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 9999
typedef struct
{
    char ch;
    int weight;
    int lchild,rchild,mother;
}hufftree;
typedef struct
{
    char code[40];
    int rnt;
}code;
void Greatree(hufftree *ww,int n)
{
    int i,j,min,cmin;
    int m,c;
    ww[0].ch=' ';//对空格做处理
    ww[0].rchild=ww[0].lchild=ww[0].mother=-1;
    printf("请输入空格的权值");
    scanf("%d",&ww[0].weight);
     printf("请输入每个字母的权值");
    for(i=1;i<n;i++)//初始化A-Z的huffman
    {
        ww[i].ch='A'+i-1;
        ww[i].lchild=ww[i].rchild=ww[i].mother=-1;
        scanf("%d",&ww[i].weight);
    }
    for(i=n;i<2*n-1;i++)
    {
        min=cmin=MAX;
        c=m=0;
        for(j=0;j<i;j++)
        {
            if(ww[j].mother==-1)
            {
                if(ww[j].weight<min)
                {
                    c=m;
                    cmin=min;
                    min=ww[j].weight;
                    m=j;
                }
                else if(ww[j].weight<cmin)
                {
                    cmin=ww[j].weight;
                    c=j;
                }
            }

        }
        ww[i].weight=min+cmin;
        ww[i].lchild=m;
        ww[i].rchild=c;
        ww[i].mother=-1;
        ww[c].mother=ww[m].mother=i;
        ww[i].ch=' ';
    }


}
void hfmcode(hufftree*ww,code*codein,int N)
 {
     int i,p,c;
     code s;
     for(i=0;i<N;i++)
     {
         c=i;
         p=ww[c].mother;
         s.rnt=N;
         s.code[N]='\0';
         while(p!=-1)
         {
             if(ww[p].lchild==c)
                s.code[--s.rnt]='0';
             else
                s.code[--s.rnt]='1';
             c=p;
             p=ww[c].mother;
         }
         codein[i]=s;
     }

 }
 void Decode(hufftree*ww,char*tobetre,int N)
 {
     char ch;
     int i,ct=0;
     scanf("%c",&ch);
     i=2*N-2;
     while(ch!='#')
     {
         if(ch=='0')
            i=ww[i].lchild;
            else if(ch=='1')
                i=ww[i].rchild;
            if(ww[i].lchild==-1||ww[i].rchild==-1)
            {
                tobetre[ct++]=ww[i].ch;
                i=2*N-2;
            }
            scanf("%c",&ch);

     }
     if((ww[i].lchild!=-1||ww[i].rchild!=-1)&&i!=2*N-2)
     printf("error");
     tobetre[ct]='\0';

 }

int main()
{
    int i,j,n=27;
    char str[]="THIS PROGRAM IS MY FAVORITE";
     char *tobetre,c;
      hufftree * ww;
      code * codein;
      tobetre=(char *)malloc(sizeof(char)*40);
      ww=(hufftree *)malloc(sizeof(hufftree)*(2*n-1));
      codein=(code *)malloc(sizeof(code)*n);
      Greatree(ww,n);
      hfmcode(ww,codein,n);
      scanf("%c",&c);
      printf("\n");
      printf("改字符的编码是：\n");
      for(i=0;i<strlen(str);i++)
      {
          if(str[i]==' ')
            printf("%s",codein[0].code+codein[0].rnt);
          else
            printf("%s",codein[str[i]-'A'+1].code+codein[str[i]-'A'+1].rnt);
      }
      printf("\n\n");
      printf("请输入要编译");
      Decode(ww,tobetre,n);
      printf("\n");
      printf("编译的译文为：\n");
      printf("%s",tobetre);
    return 0;
}






