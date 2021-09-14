#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct ListNode {
     int val;
     struct ListNode *next;
 };
 int getDecimalValue(struct ListNode* head);
 int main(void)
 {
     struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
     head -> val = 1;
     head -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
     head -> next -> val = 3;
     head -> next -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
     head -> next -> next -> val = 2;
     head -> next -> next -> next = NULL;
     int result = getDecimalValue(head);
     printf("%d",result);
     return 0;

 }
 int getDecimalValue(struct ListNode* head){
    int i = 0,value = 0;
    struct ListNode * thisnode ,* nextnode;
    thisnode = head;
    nextnode = thisnode -> next;
    while(nextnode != NULL){
        i ++;
        thisnode = nextnode;
        nextnode = nextnode -> next;
    }
    i ++;
    thisnode = head;
    nextnode = thisnode -> next;
    int k = 0,l = i;
    while(k < l){
        value = value + (thisnode -> val) * pow(2,i - 1);
        i --;
        k ++;
        if(i == 0)
        break;
        thisnode = nextnode;
        nextnode = nextnode -> next;
    }
    return value;
}