#include "com.h" 
void browse() 
{ 
	S_MESSAGE*p1; 
	if(head==NULL&&tail==NULL) 
	{ 
		printf("\n-------��ǰ��Ϣ��¼Ϊ��-------\n"); 
	} 
	else 
	{ 
		printf("\n-------��Ҫ�����ѡ����Ϣ����-------\n"); 
		printf("---------|-------\n"); 
		printf("���|����\n"); 
		p1=head; 
		while(p1!=NULL) 
		{ 
			printf("---------|-------\n"); 
			printf("%-9d%-6s\n",p1->num,p1->name); 
			p1=p1->next; 
		} 
		printf("---------|-------\n"); 
	} 
} 
