#include "com.h"
void creat(int n) 
{ 
	int i,j; 
	float t; 
	char c='y'; 
	while(c=='y'||c=='Y') 


 	{ 
		S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN); 
		printf("\n ������Ҫ¼���ѡ����Ϣ��\n"); 
		printf("\n ѡ�ֱ�ţ�"); 
		scanf("%d",&p1->num); 
		
		printf("\nѡ������:");
		scanf("%s",p1->name);
		printf("\n������7λ��ί�����ɼ���");
		
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
				printf("\n�ڴ����ʧ��\n");
				n=n-1;
				
			}
			if(head==NULL&&tail==NULL)
			{
				head=p1;
				head->next=NULL;
				tail=head;
				printf("\n-----ѡ����Ϣ¼��ɹ�-----\n");
			}
			else
			{
				tail->next=p1;
				tail=p1;
				tail->next=NULL;
				printf("\n------ѡ����Ϣ¼��ɹ�-----\n");
			}
			printf("�Ƿ����(Y/N):");
			getchar();
			scanf("%c",&c);
	} 
 } 
