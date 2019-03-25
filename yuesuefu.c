#include <stdio.h>
#include <stdlib.h>
# define N 7
typedef struct Node
{
     int  data;
     int  number;
     struct Node *next;

}List;
 List *creat()
 {
     List* head;
     head=(List*)malloc(sizeof(List));
     scanf("%d",&head->data);
     head->number=1;
     head->next=NULL;
     return head;

 }
 List*tailinsert(List* head ,int password ,int i,int n)
 {
    List *p,*t;
	t=head;
	p=(List *)malloc(sizeof(List));
	p->data=password;
	p->number=i+1;
	while(t->next!=NULL)
	t=t->next;
	t->next=p;
	p->next=NULL;
	if(i==n-1)
        p->next=head;
	return head;
 }
 /*List* listfree(List*p)
 {
     List *pnext;
     pnext=p->next;
     (p-1)->next=p->next;
     free(p);
     return pnext;
 }
 */
  void listdelete(List* head,int password,int n)
 {
     List *p= head;
     List *apnext;
     int j=0;
     while(n>1)
     {

         for(j=1;j<password;j++)
         {
             p=p->next;
         }

                    apnext=p->next;
                    p->next=apnext->next;
                    password=apnext->data;
                    printf("%d",apnext->number);
                    free(apnext);

            n--;
     }
     printf("%d",p->number);
 }
/*void print_list(List *L)
{
    List *p = L;
    while (NULL != p)
    {
        if(p->data<=20)
        printf("%d ", p->data);
        printf("%d ",p->number);
        if (p->next != NULL)
        {
            printf("-> ");
        }
        p = p->next;
    }

    printf("\n");
}
*/
int main()
{

    int i=0,passworad,m;
    int n=N;
    printf("请输入密码的上线");
    scanf("%d",&m);
    printf("请输入mima");
     List *ptry=creat();
    for(i=1;i<n;i++)
    {
        scanf("%d",&passworad);

        tailinsert(ptry,passworad,i,n);

    }
    listdelete(ptry,m-1,n);
    return 0;

}
