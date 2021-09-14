#include<stdio.h>
#include<stdlib.h>
struct node
{
    int element;
    struct node * next;
};
int FindMax(struct node* p);
int FindMin(struct node* p);
int Sum(struct node* p);
int main(void) {
    struct node head;
    struct node * header = &head;
    head.element = 0;
    head.next = NULL;
    struct node * p = header;
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
    int min = FindMin(header);
    int max = FindMax(header);
    int sum = Sum(header);
    printf("The maximum,minmum and the total are:%d %d %d",max,min,sum);
    return 0;
}
int FindMax(struct node* p)
{
    struct node * h = p;
    h = h->next;
    int max = (h->element);
    while (h != NULL)
    {
        if(h->element > max){
            max = h->element;
        }
        h = h->next;
    }
     return max;
}
int FindMin(struct node* p)
{
    struct node * h = p;
    h = h->next;
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
int Sum(struct node* p)
{
    int sum = 0;
    struct node * h = p;
    h = h->next;
    while (h != NULL)
    {
        sum = sum + (h->element);
        h = h->next;
    }
    return sum;
}