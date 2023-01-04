#include<stdio.h>
#include<stdlib.h>
//구조체 Node 생성. 정수 value, 구조체 포인터 next 선언. ListNode로 이름 축약.
typedef struct Node{
int value;			 //정수 value,
//
struct Node *next;	// 구조체 포인터 next 선언.
} ListNode; //ListNode로 구조체 단순화.

int insertNode(ListNode **ptrHead,int value){				 //포인터 사용 이유 - 이미 생성된 구조체 다시 만들어오면 메모리 부하증가.
ListNode *tempNode =(ListNode*)malloc(sizeof(ListNode));	//임시 구조체(동적) 생성.
if(!tempNode){												//생성 안될시 종료.
return -1;
}
tempNode->value =value;										//임시 구조체->value에 입력받은 value 대입.
//
tempNode->next = *ptrHead;									//임시 구조체->next에 입력반은 구조체 포인터 ptrhead의 값 대입.
*ptrHead = tempNode;										//head에 임시구조체 대입.
return 1;
}

int insertEnd(ListNode **ptrHead,int value){
	ListNode *head =*ptrHead;
	ListNode *tempNode =(ListNode*)malloc(sizeof(ListNode));
	if(!tempNode){
		return -1;
		}
	
		tempNode->value =value;
		tempNode->next =NULL;
	
	if(head == NULL){
		tempNode->next = *ptrHead;
		*ptrHead = tempNode;
		return 1;
	}
	while(head->next !=NULL){
		head = head->next;
	}
	tempNode->next =head->next;
	head->next = tempNode;

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
	ListNode *head=NULL;		//구조체 포인터 head 값 NULL로 초기화 
	insertNode(&head,1);		//구조체 포인터 head value에 1 대입. 구조체next에 이전 구조체head 대입.
	insertNode(&head,2);		//구조체 포인터 head value에 2 대입. 구조체next에 이전 구조체head 대입.
	insertNode(&head,3);		//구조체 포인터 head value에 3 대입. 구조체next에 이전 구조체head 대입.
	insertEnd(&head,4);
	printList(head);			//
	


return 0;
}
