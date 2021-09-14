#include<stdio.h>
#include<stdlib.h>
struct node{
    int element;
    struct node * next;
};
int main(void)
{
    struct node* headA;
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
        sizeA ++;
        p->next = NULL;
        scanf("%d",&i);
    }
    struct node* headB;
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
        sizeB ++;
        p->next = NULL;
        scanf("%d",&b);
    }
    struct node* pa = headA->next;
    struct node* pb = headB->next;
    int ListA[sizeA];
    int ListB[sizeB];
    int ia = 0;
    int ib = 0;
    while (pa != NULL)
    {
        ListA[ia] = pa->element;
        ia ++;
        pa = pa->next;
    }
    while (pb != NULL)
    {
        ListB[ib] = pb->element;
        ib ++;
        pb = pb->next;
    }
    int isSubSequence = 0;
    if(sizeB == 1)
    {
        for(int i = 0;i < sizeA;i ++)
        {
            if(ListA[i] == ListB[0])
            isSubSequence = 1;
        }
    }
    if(sizeA != 1 && sizeB != 1)
    {
            for(int p = 0;p < ia; p ++)
            {
                if(ListA[p] == ListB[0])
                {
                    for(int q = p + 1,l = 1 ;l < sizeB;l ++,q ++)
                    {
                        if(ListA[q] == ListB[l])
                        isSubSequence = 1;
                        else{
                            isSubSequence = 0;
                            break;
                        }
                    }
                }
            }
    }
    if(isSubSequence)
    printf("ListB is the sub sequence of ListA.");
    else
    printf("ListB is not the sub sequence of ListA.");
    struct node* p1 = headA;
    struct node* p2 = headB;
    while (p1 != NULL)
    {
        struct node* temp = p1;
        p1 = p1->next;
        free(temp);
    }
        while (p2 != NULL)
    {
        struct node* temp = p2;
        p2 = p2->next;
        free(temp);
    }
    return 0;
}