#include "com.h"
void creat(int n) 
{ 
	int i,j; 
	float t; 
	char c='y'; 
	while(c=='y'||c=='Y') 


 	{ 
		S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN); 
		printf("\n 请输入要录入的选手信息：\n"); 
		printf("\n 选手编号："); 
		scanf("%d",&p1->num); 
		
		printf("\n选手姓名:");
		scanf("%s",p1->name);
		printf("\n请输入7位评委点评成绩；");
		
		p1->ave=0;
		for(i=0;i<N;i++)
		{
			scanf("%f",&(p1->grades[i]));
			p1->ave+=p1->grades[i];
			
		} 
		for(i=0;i<N-1;i++)
		for(j=0;j<N-1-i;j++)
			if(p1->grades[j]>p1->grades[j+1])
			{
				t=p1->grades[j];
				p1->grades[j]=p1->grades[j+1];
				p1->grades[j+1]=t;
			}
			p1->ave=(p1->ave-(p1->grades[0]+p1->grades[9]))/8;
			p1->next=NULL;
			if(p1==NULL)
			{
				printf("\n内存分配失败\n");
				n=n-1;
				
			}
			if(head==NULL&&tail==NULL)
			{
				head=p1;
				head->next=NULL;
				tail=head;
				printf("\n-----选手信息录入成功-----\n");
			}
			else
			{
				tail->next=p1;
				tail=p1;
				tail->next=NULL;
				printf("\n------选手信息录入成功-----\n");
			}
			printf("是否继续(Y/N):");
			getchar();
			scanf("%c",&c);
	} 
 } 
