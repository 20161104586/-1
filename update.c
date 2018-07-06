#include "com.h" 
void update(int n)
{
	S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN); 
	int check=0;
	long updatenum;
	printf("\n请输入要修改的选手编号：");
	scanf("%d",&updatenum);
	if(head==NULL&&tail==NULL)
	{
		printf("\n------当前信息记录为空-----\n");
	} 
	else
	{
		while(p1!=NULL)
		{
			if(p1->num==updatenum)
			{
				printf("\n------你要修改的选手信息如下-----\n");
				printf("------|-----\n");
				printf("编号|姓名\n");
				printf("------|-----\n");
				printf("%-9d%-6s\n",p1->num,p1->name); 
				printf("------|-----\n");
				printf("\n------请重新写入此选手信息：-----\n");
				check=1;
				printf("\n修改选手编号为：");
				scanf("%d",&p1->num);
				printf("\n修改选手姓名为：");
				scanf("%s",p1->name);
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
		printf("\n对不起，你要修改的选手信息不存在！\n");
	}
	getchar();
	
}

