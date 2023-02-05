#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>


//구조체 Node 생성. 정수 value, 구조체 포인터 next 선언. ListNode로 이름 축약.
typedef struct Node{
	int num;					//정수 value,
	char name[20];
	int english;
	int math;
	int korean;		//
	struct Node *next;	// 구조체 포인터 next 선언.
} NODE; //ListNode로 구조체 단순화.

NODE *head=NULL;

NODE* createNode(){
	
	int s_english,s_math,s_korean;
	char n_name[20];
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	srand((unsigned int)time(NULL));
	
	printf("name : ");
	scanf("%s",n_name);
	s_english=rand()%100;
	s_math=rand()%100;
	s_korean=rand()%100;
	
	temp->english =s_english;
	temp->math =s_math;
	temp->korean =s_korean;
	for(int i =0; i<20; i++){
		temp->name[i] = n_name[i]; 
	}
	
	temp->next = NULL;
	
	return temp;
}
//현재 리스트의 맨 뒤에 노드를 추가해주는 함수
void addNode(NODE **head){
	// 전달받은 값을 저장하는 새로운 노드를 생성한다.
	NODE *newNode = createNode();
	// 헤드에 아무것도 없을 경우
	// 즉, 현재 노드가 하나도 없을 경우
	if(*head == NULL)
	{
		// 헤드에 생성한 노드를 연결
		newNode->num =1;
		printf("학생 번호 : %d\n",newNode->num);
		printf("english : %d  ",newNode->english);
		printf("math : %d  ",newNode->math);
		printf("korean : %d\n",newNode->korean);
		*head = newNode;
	}
	else
	{
		NODE *temp = *head;
		// 마지막 노드를 찾는 루프
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		// 마지막 노드일 경우 새로 생성한 노드 연결'
		newNode->num +=1;
		printf("학생 번호 : %d\n",newNode->num);
		printf("english : %d  ",newNode->english);
		printf("math : %d  ",newNode->math);
		printf("korean : %d\n",newNode->korean);
		temp->next = newNode;
		
	}
}
void print_node(){
	NODE * curr = head;
	printf("\n+++++ 학생 정보 +++++\n");
	while(curr != NULL){
		printf("korean : %d  \n",curr->korean);
		printf("math : %d  \n",curr->math);
		printf("english : %d  \n",curr->english);
		printf("name : %s  \n",curr->name);
		printf("NODE(p) : %p\n",curr);
	
		curr = curr->next;
	}
	printf("+++++ 학생 정보 +++++\n\n");
}
void free_node(){
	NODE * curr = head;
	
	while(curr != NULL){
		free(curr);
		curr = curr->next;
	}
}
void del_node(){
	NODE * curr = head;
	char yesorno[20];
	
	printf("정말 모든학생의 정보를 삭제하시겠습니까? (yes or no) : ");
	scanf("%s",yesorno);
	
	if(strcmp(yesorno,"yes") ==0 || strcmp(yesorno,"YES") ==0 ) //yesorno가 yes이거나 YES일떄 strcmp비교를통해 같으면 0이 반환 됨 
	{
		head = NULL;
	}
}
void search_node(){
	char check_name[20]; 
	int n_count,check = 0;
	
	printf("찾을 학생의 이름 ex)홍길동 : ");
	scanf("%s",check_name);
	
	NODE *cur = head;
	while(cur != NULL){
		
		if(cur->name == check_name)
		{
		printf("korean : %d | ",cur->korean);
		printf("math : %d | ",cur->math);
		printf("english : %d | ",cur->english);
		printf("name : %s | ",cur->name);
		}
			
		cur= cur->next;
	}
}
int main(void)
{
	// 리스트의 가장 처음 노드를 가르키는 포인터
	int menu = 0; 
	while(menu!=5){
		printf("학생 정리 관리 프로그램 \n --------------------------------------------------------------------------------\n1. 학생 수 입력\n2. 학생 정보 삭제\n3. 학생 검색\n4. 학생 정보 출력\n5. 프로그램 종료\n--------------------------------------------------------------------------------\n메뉴 선택 : ");
		scanf("%d",&menu);
		
		switch(menu){
			case 1:
				addNode(&head); //학생정보 추가
				break;
			case 2:
				del_node(); //모든학생의 데이터 삭제 
				break;
			case 3:
				search_node(); //학생의 생년월일을 입력하고 해당학생을 찾아 출력
				break;
			case 4:
				print_node(); //모든학생정보를 출력
				break;
			case 5:
				free_node(); //종료
				break;
		}
	}
	return 0;
}