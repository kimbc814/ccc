#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
int value;
struct Node *next;
} ListNode;

int insertNode(ListNode **ptrHead,int value){
ListNode *tempNode =(ListNode*)malloc(sizeof(ListNode));
if(!tempNode){
return -1;
}
tempNode->value =value;
tempNode->next = *ptrHead;
*ptrHead = tempNode;

return 1;
}
int printList(ListNode *head){
	printf("list : ");
	while(head){
		printf("%d",head->value);
		head = head->next;
	}
	printf("\n");
}

int main(){
	ListNode *head=NULL;
	insertNode(&head,1);
	insertNode(&head,2);
	insertNode(&head,3);
	printList(head);
	


return 0;
}
