#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}Node;
void buildlist(Node *head);
void freelist(Node *head);
void print(Node *head);
 int main()
{
    
 Node *head[3], *be1, *be2, *p1, *p2, *r1, *r2;
    int i;
    head[0]=NULL;
    for(i=1;i<3;i++)
    {
        head[i]=(Node*)malloc(sizeof(Node));
  buildlist(head[i]);
  }
  
 be1=head[1];
 be2=head[2];
 p1=be1->next;
 p2=be2->next;
 while(p2!=NULL&&p1!=NULL)
 {
  
  if(p1->data == p2->data)
  {
   be2=p2;
   p2=be2->next;
  }
  else if(p1->data > p2->data)
  {
   r2=p2->next;
      be1->next=p2;
      p2->next=p1;
      be2->next=r2;
      p2=r2;
  }
  else 
  {
   while((p1->data < p2->data) || p1->next!= NULL)
      {
       
       be1=p1;
       p1=be1->next;
      }
  }
 }
 if(p1->next==NULL)
 {
  p1->next=p2;
  be2->next=NULL;
 }
 if(head[1]->next!=NULL)
 {
  printf("The new list A:");
     print(head[1]);
 }
 else{
  printf("There is no item in A list.");
 }
 if(head[2]->next!=NULL)
 {
  printf("The new list B:");
     print(head[2]);
 }
 else{
  printf("There is no item in B list.");
 }
 
 freelist(head[1]);
 freelist(head[2]);
 
 return 0;
}

void buildlist(Node *head)
{
 Node *last, *cur;
 
 last=head;
 
 int x;
 scanf("%d",&x);
 while(x!=-1)
 {
  cur=(Node*)malloc(sizeof(Node));
  cur->data=x;
  cur->next=NULL;
  last->next=cur;
  last=cur;
  scanf("%d",&x);
 }
}

void freelist(Node *head)
{
 Node *p, *r;
 p=head;
  while(p->next!=NULL)
 {
  r=p->next;
  free(p);
  p=r;
 }
}
void print(Node *head)
{
 Node *p;
 p=head->next;
 while(p != NULL)
 {
  printf("%d ",p->data);
  p=p->next;
 }
 printf("\n");
}