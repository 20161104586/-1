#include "com.h" 
void search(int n) 
{ 
	S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN); 
	int check=0,i; 
	long seeknum; 
	printf("\n������Ҫ���ҵ�ѡ�ֱ�ţ�"); 
	scanf("%d",&seeknum); 
	if(head==NULL&&tail==NULL) 
	{ 
		printf("�Բ��𣬵�ǰ��¼Ϊ�գ�\n"); 
	}  
	else 
	{ 
		p1=head; 
		printf("\n--------��Ҫ�ҵ�ѡ�ֵĳɼ�����--------\n"); 
		printf("-------|-------|-------|--------\n"); 
		printf("���|����|�ɼ�|1|2|3|4|5|6|7|ƽ���ɼ�\n"); 
		printf("-------|-------|-------|--------\n"); 
		while(p1!=NULL) 
		{ 
			if(p1->num==seeknum) 
			{ 
				printf("%-7d%-6s",p1->num,p1->name); 
				printf(" "); 
				for(i=0;i<N;i++) 
				{ 
					printf("%.1f",p1->grades[i]); 
				} 

				check=1; 
				getchar(); 
				return; 
			} 
			else 
			{ 
				p1=p1->next; 
			} 
		 }  
	} 

	if(head!=NULL&&check==0) 
	{ 
		printf("\n�Բ�����鿴��ѡ�ֳɼ�������!\n"); 
	} 
	getchar(); 
} 
