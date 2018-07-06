#include "com.h" 
void browse() 
{ 
	S_MESSAGE*p1; 
	if(head==NULL&&tail==NULL) 
	{ 
		printf("\n-------当前信息记录为空-------\n"); 
	} 
	else 
	{ 
		printf("\n-------你要浏览的选手信息如下-------\n"); 
		printf("---------|-------\n"); 
		printf("编号|姓名\n"); 
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
