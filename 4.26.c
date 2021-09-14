#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  char str;
  struct node *next;
}Node;
void splitlist(Node *headL,Node *headA,Node *headB,Node *headC);
void bubblesort(Node *head);
void freelist(Node *head);
void print(Node *head);
int main()
{
 Node *headL, *headA, *headB, *headC;
 Node *p, *r;
 char s[1000];
 int i=0; 
 gets(s);
 headL=(Node*)malloc(sizeof(Node));
 p=headL;
 
 while(!(s[i+1]=='-'&&s[i+2]=='1'))
 {
  if(s[i]==' ')
  {
   i++;
  } 
  r=(Node*)malloc(sizeof(Node));
  r->str=s[i];
  r->next=NULL;
  p->next=r;
  p=r;
  i++;
 }
 headA=(Node*)malloc(sizeof(Node));
 headB=(Node*)malloc(sizeof(Node));
 headC=(Node*)malloc(sizeof(Node));
 splitlist(headL,headA,headB,headC);
 bubblesort(headA);
 bubblesort(headB);
 bubblesort(headC); 
 if(headA->next!=NULL)
 {
  printf("The list A is: ");
  print(headA);
 }
 else
 {
  printf("There is no item in A list.\n");
 }
 if(headB->next!=NULL)
 {
  printf("The list B is: ");
     print(headB);
 }
 else
 {
  printf("There is no item in B list.\n");
 }
 if(headC->next!=NULL)
 {
  printf("The list C is: ");
     print(headC);
 }
 else
 {
  printf("There is no item in C list.\n");
 }
 freelist(headL);
 freelist(headA);
 freelist(headB);
 freelist(headC);
 return 0;
}

void splitlist(Node *headL,Node *headA,Node *headB,Node *headC)
{
 Node *p, *r;
 p=headL;
 r=p->next;
 Node *pa, *pb, *pc;
 pa=headA;
 pa->next=NULL;
 pb=headB;
 pb->next=NULL;
 pc=headC;
 pc->next=NULL;
 while(p->next!=NULL)
 {
  if((r->str>='a'&&r->str<='z')||(r->str>='A'&&r->str<='Z'))
  {
   pa->next=r;
   r=r->next;
   p->next=r;
   pa=pa->next;
   pa->next=NULL;
  }
  else if(r->str>='0'&&r->str<='9')
  {
   pb->next=r;
   r=r->next;
   p->next=r;
   pb=pb->next;
   pb->next=NULL;
  }
  else
  {
   pc->next=r;
   r=r->next;
   p->next=r;
   pc=pc->next;
   pc->next=NULL;
  }
 }
} 

void bubblesort(Node *head)
{
 Node *p, *r;
 Node *last = NULL;
 
 while(last != head->next)
 {
  p = head;
  r = head->next;
  while(r->next != last){
   if(r->str > r->next->str){
    p->next = p->next->next;
				r->next = r->next->next;
				p->next->next = r;
			}
			else r = r->next;
			p = p->next;
		}
		last = r;
	}
}

void freelist(Node *head)
{
	Node *p, *r;
	p=head;
	while(p!=NULL)
	{
		r=p->next;
		free(p);
		p=r;
	}
}

void print(Node *head)
{
    Node * tem;
    tem = head -> next;
    while(tem != NULL)
    {
        printf("%c ", tem->str);
        tem = tem -> next;
    }
    printf("\n");
}
