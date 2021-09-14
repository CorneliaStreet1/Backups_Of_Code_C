#include<stdio.h>
#include<stdlib.h>
struct node{
    int element;
    struct node * next;
};
void mergeSortList(struct node* head1Ptr,struct node** last1PtrPtr, struct node* head2Ptr, struct node* * last2PtrPtr );
int main(void)
{
    struct node* headA;
    struct node* lastA;
    headA =(struct node*) malloc(sizeof(struct node));
    headA->element = -1;
    headA->next = NULL;
    struct node * p = headA;
    int i;
    int sizeA = 0;
    scanf("%d",&i);
    while (i != -1)
    {
        p->next = (struct node *)malloc(sizeof(struct node));
        p = p->next;
        p->element = i;
        lastA = p;
        sizeA ++;
        p->next = NULL;
        scanf("%d",&i);
    }
    struct node* headB;
    struct node* lastB;
    headB =(struct node*) malloc(sizeof(struct node));
    headB->element = -1;
    headB->next = NULL;
    p = headB;
    int b;
    int sizeB = 0;
    scanf("%d",&b);
    while (b != -1)
    {
        p->next = (struct node *)malloc(sizeof(struct node));
        p = p->next;
        p->element = b;
        lastB = p;
        sizeB ++;
        p->next = NULL;
        scanf("%d",&b);
    }
    mergeSortList(headA,&lastA,headB,&lastB);
    if(headA->next == NULL)
    printf("There is no item in A list\n");
    else{
        printf("The new list A:");
        struct node* p2 = headA->next;
        while (p2 != NULL)
       {
           printf("%d",p2->element);
           if(p2->next != NULL)
           printf(" ");
           else
           printf("\n");
           p2 = p2->next;
       }
    }
    if(headB->next == NULL)
    printf("There is no item in B list\n");
    else{

        printf("The new list B:");
        struct node* p1 = headB->next;
        while (p1 != NULL)
        {
            printf("%d",p1->element);
            if(p1->next != NULL)
            printf(" ");
            else
            printf("\n");
            p1 = p1->next;
        }
    }
    struct node* F = headA;
    while (F != NULL)
    {
        struct node * temp = F;
        F = F->next;
        free(temp);
    }
    struct node* T = headB;
    while (T != NULL)
    {
        struct node* Temp = T;
        T = T->next;
        free(Temp);
    }
    return 0;
}
void mergeSortList(struct node* head1Ptr,struct node** last1PtrPtr, struct node* head2Ptr, struct node* * last2PtrPtr )
{
    struct node* first1;
    struct node* first2;
    struct node* pre1;
    struct node* pre2;
    first1 = head1Ptr->next;
    first2 = head2Ptr->next;
    pre1 = head1Ptr;
    while (first1 != NULL &&first2 != NULL )
    {
        if(first2->element < first1->element){
            struct node* temp2 = first2->next;
            pre1->next = first2;
            pre1 = first2;
            first2->next = first1;
            first2 = temp2;
        }
        else{
            pre1 = first1;
            first1 = first1->next;
        }
    }
    if(first2 != NULL){
        pre1->next = first2;
        *last1PtrPtr = *last2PtrPtr;
    }
    head2Ptr->next = NULL;
    *last2PtrPtr = head2Ptr;
}