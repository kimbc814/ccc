#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int list [MAX]={1,2,3,4,5,0,0,0,0,0};


int insertlist(int list1[],int i,int value){
	int templist=0;

	for(int j=MAX;j>=i;j--){
	 	templist=list1[j-1];
	 	list1[j]=templist;
	 }
	
	list1[i]=value;
return 1;
}
int insertlist_end(int list1[],int value){
	
	
	for(int j=MAX;j>0;j--){
		if(list1[j]!=0){
			list1[j+1] = value;
			break;
		}
	}
	return 1;
}

int main(){
	int value;
	int arr_num;
	
	
	printf("배열 (번호, 값) _ _\b\b\b");
	scanf("%d %d",&arr_num,&value);
	insertlist(list,arr_num-1,value);
	puts("");
	for(int i=0;i<MAX;i++){
		printf("배열   %2d = %d\n",i+1,list[i]);
	}
	
	printf("마지막 배열 (값) _\b");
	scanf("%d",&value);
	insertlist_end(list,value);
	puts("");
	for(int i=0;i<MAX;i++){
		printf("배열   %2d = %d\n",i+1,list[i]);
	}

return 0;
}
