#include<stdio.h>
#include<stdlib.h>
struct node{
    int element;
    struct node * next;
};
void SelectSort(struct node *);
int FindMin(struct node* p);
int main(void)
{
    struct node * head = (struct node *)malloc(sizeof(struct node));
    head->element = - 1;
    head->next = NULL;
    struct node * p = head;
    int i;
    scanf("%d" , &i);
    while (i != -1)
    {
        p->next = (struct node *) malloc(sizeof(struct node));
        p = p->next;
        p->element = i;
        p->next = NULL;
        scanf("%d",&i);
    }
    SelectSort(head);
    printf("The new list is:");
    struct node * pt = head->next;    
    while (pt != NULL)
    {
        printf("%d",pt->element);
        if(pt->next != NULL){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
void SelectSort(struct node * p)
{
    struct node * h = p->next;
    struct node * copy = (struct node * )malloc(sizeof(struct node));
    struct node* pt = copy;
    while (h->next != NULL)
    {
        int min = FindMin(h);
        pt->next = (struct node *) malloc(sizeof(struct node));
        pt->element = min;
        pt->next = NULL;
         = h->next;
    }
    
}
int FindMin(struct node* p)
{
    struct node * h = p;
    int min = h->element;
    while (h != NULL)
    {
        int p = h ->element;
        if(h->element < min){
            min = h->element;
        }
        h = h->next;
    }
     return min;
}