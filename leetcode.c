#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct ListNode {
     int val;
     struct ListNode *next;
 };
 int* reversePrint(struct ListNode* head, int* returnSize);
 int main(void)
 { 
     struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
     head -> val = 1;
     head -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
     head -> next -> val = 3;
     head -> next -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
     head -> next -> next -> val = 2;
     head -> next -> next -> next = NULL;
     int returnSize;     
     int * a = reversePrint(head,&returnSize);
     for(int i = 0 ; i < returnSize ; i ++)
     printf("%d ",a[i]);
     return 0;

 }
 int* reversePrint(struct ListNode* head, int* returnSize){
    struct ListNode * thisnode,*nextnode;
    thisnode = head;
    nextnode = head -> next;
    int i = 1;
    while(nextnode != NULL){
        i ++;
        thisnode = nextnode;
        nextnode = nextnode -> next;
    }
    *returnSize = i;
    int * num = (int *)malloc(sizeof(int) * i);
    thisnode = head;
    nextnode = head -> next;
    int k = i - 1;
    while(nextnode != NULL){
        int p = thisnode -> val;
        num[k] = thisnode -> val; 
        thisnode = nextnode;
        nextnode = nextnode -> next;
        k --;
    }
    num[k] = thisnode -> val;
    return num;
}