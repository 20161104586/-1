#include "com.h" 
void search(int n) 
{ 
	S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN); 
	int check=0,i; 
	long seeknum; 
	printf("\n请输入要查找的选手编号："); 
	scanf("%d",&seeknum); 
	if(head==NULL&&tail==NULL) 
	{ 
		printf("对不起，当前记录为空！\n"); 
	}  
	else 
	{ 
		p1=head; 
		printf("\n--------你要找的选手的成绩如下--------\n"); 
		printf("-------|-------|-------|--------\n"); 
		printf("编号|姓名|成绩|1|2|3|4|5|6|7|平均成绩\n"); 
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
		printf("\n对不起，你查看的选手成绩不存在!\n"); 
	} 
	getchar(); 
} 
