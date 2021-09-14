#include<stdio.h>
#include<stdlib.h>
struct node{
    int element;
    struct node * next;
};
int main(void)
{
    struct node* head;
    head =(struct node*) malloc(sizeof(struct node));
    head->element = -1;
    head->next = NULL;
    struct node * p = head;
    int i;
    int size = 0;
    scanf("%d",&i);
    while (i != -1)
    {
        p->next = (struct node *)malloc(sizeof(struct node));
        p = p->next;
        p->element = i;
        size ++;
        p->next = NULL;
        scanf("%d",&i);
        vvvvvvvvvvvvv
    }
    struct node * nodes[size];
    struct node * p1 = head->next;
    int l = 0;
    while (p1 != NULL)
    {
        nodes[l] = p1;
        p1 = p1->next;
        l ++;
    }
    for(int t = 0;t < size ; t ++)
    {
        int min = t;
        for(int q = t;q < size ;q ++){
            if(nodes[q]->element < nodes[min]->element)
            min = q;
        }
        nodes[min]->next = nodes[t]->next;
        if(t != 0)
        nodes[t - 1]->next = nodes[min];
        else
        head->next = nodes[min];
        if(min != size - 1)
        nodes[t]->next = nodes[min + 1];
        else
        nodes[t]->next = NULL;
        nodes[min - 1]->next = nodes[t];
        struct node* temp = nodes[t];
        nodes[t] = nodes[min];
        nodes[min] = temp;
    }
    printf("The new list is:");
    struct node* p2 = head->next;
    while (p2 != NULL)
    {
        printf("%d",p2->element);
        if(p2->next != NULL)
        printf(" ");
        else
        printf("\n");
        p2 = p2->next;
    }
    for(int u = 0;u < size; u ++)
    {
        free(nodes[u]);
    }
    free(head);
    return 0;
}