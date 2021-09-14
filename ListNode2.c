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
    }
    struct node * nodes[size + 1];
    struct node * p1 = head;
    int l = 0;
    while (p1 != NULL)
    {
        nodes[l] = p1;
        p1 = p1->next;
        l ++;
    }
    int s1,t1,s2,t2;
    scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
    nodes[s2 - 1]->next = nodes[s1];
    if(t2 == size )
    nodes[t1]->next = NULL;
    else
    nodes[t1]->next = nodes[t2 + 1];
    nodes[t2]->next = nodes[t1 + 1];
    nodes[s1 - 1]->next = nodes[s2];
    nodes[t2]->next = nodes[s1 + 1];
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
