#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int putarr2(int **arr1,int class, int person){
	
	
	//배열에 랜덤값 저장.
	srand((unsigned int)time(NULL));
	for(int i =0; i<class;i++){
		for(int j =0;j<person;j++){
			if(i==0){
				arr1[i][j]=j+1;
			}
			else arr1[i][j]=rand()%100;
		}
	}
	//출력
	printf("\n         ");
	for(int i=0;i<class;i++){
		for(int j=0;j<person;j++){
			if(i==0){
				printf("||   학생 %d   ",j+1);
				if(j==person-1)printf("||\n");
			}
			else printf("점수 = %3d || ",arr1[i][j]);
		}
		if(i<class-1)printf("\b\b\n- 과목 %d || ",i+1);
	}
	puts("");
	return 0;
}

int find_first(int **arr1,int class, int person){
	int list[class][person][2];//순위 배열 선언.
	int temp1=0,temp2=0;//임시값 저장용 변수 선언.
	//순위 배열에 값 저장.
	for(int i =1; i<class+1;i++){
		
		for(int k=0;k<person;k++){
			list[i-1][k][0]=arr1[i][k];
			list[i-1][k][1]=arr1[0][k];
		}
		//순위 배열 순위별로 정렬.
		for(int m=0;m<person-1;m++){
				for(int n=0;n<person-1;n++){
					if(list[i-1][n][0]<list[i-1][n+1][0]){
						
						temp1= list[i-1][n][0];
						temp2= list[i-1][n][1];
						
						list[i-1][n][0] = list[i-1][n+1][0];
						list[i-1][n][1] = list[i-1][n+1][1];
						
						list[i-1][n+1][0] = temp1;
						list[i-1][n+1][1] = temp2;
					}
					
				}
			}
	}
	//순위배열 출력
	for(int k=0;k<class;k++){
		printf("||  과목%d 등수 점수 사람  ",k+1);
	}
	printf(" ||\n");
	for(int ii =0;ii<person;ii++){
		for(int jj=0;jj<class;jj++){
			printf("||         %d등  %3d  %3d  ",ii+1,list[jj][ii][0],list[jj][ii][1]);
			}
		printf(" ||\n");
	}	
}
float avg_score(int **arr1,int class, int person){
	float *avg=(float*)malloc(sizeof(float)*class);//평균 계산 동적 배열 할당.
	for(int i=0;i<class;i++) avg[i]=0;//배열 값 초기화.
	
	//평균 계산 , 출력.
	for(int i=1;i<class+1;i++){
		for(int j=0;j<person;j++){
			avg[i]+=arr1[i][j];
		}
		avg[i]=avg[i]/person; 
		printf("||  과목%d 평균 %3.1f       ",i,avg[i]);
	}
	printf(" ||\n");
	free(avg);
	return 0;
}

int main(){
	
	//과목 수, 인원 입력.
	int class,person;
	printf("- 과목 수 : ");
	scanf("%d%*c",&class);
	printf("- 학생 수 : ");
	scanf("%d%*c",&person);
	
	//과목 수, 인원 2차원 동적할당.
	int **test =(int**)malloc(sizeof(int*)*class+1);
	for(int i=0;i<person;i++){
		test[i]=(int*)malloc(sizeof(int)*person);
	}
	putarr2(test,class+1,person);
	puts("");
	find_first(test,class,person);
	avg_score(test,class,person);
	
	/*for(int i=0;i<person;i++){
		free(test[i]);
	}*/
	free(test);
	return 0;	
}