#include<stdio.h>
#include<stdlib.h>
struct node{
    int element;
    struct node * next;
};
void SelectSort(struct node *);
int main(void)
{
    struct node * head = (struct node *)malloc(Sizeof(struct node));
    head->element = -1;
    head->next = NULL;
    struct node * p = head;
    int i;
    scanf("%d", &i);
    while(i != -1){
        p->next = (struct node *)malloc(sizeof(struct node));
        p = p->next;
        p->element = i;
        scanf("%d",i);
    }
    SelectSort(head);
}
void SelectSort(struct node *)
{
    
}