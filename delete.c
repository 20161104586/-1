#include "com.h" 
void del(int n)
{
	S_MESSAGE*node=(S_MESSAGE*)malloc(LEN); 
	S_MESSAGE*p1; 
	int check=0;
	long del_num;
	printf("\n请输入要删除的选手的编号:");
	scanf("%d",&del_num);
	if(head==NULL&&tail==NULL)
	{
		printf("\n当前信息记录为空,删除失败！\n");
	 } 
	 else
	 {
	 	node=head;
	 	p1=head;
	 	while(node!=NULL)
	 	{
	 		if(node->num==del_num)
	 		{
	 			printf("\n------要删除的选手信息-----\n");
	 			printf("------|-----\n");
				printf("编号|姓名\n");
				printf("------|-----\n");
				printf("%-9d%-6s\n",node->num,node->name); 
				printf("------|-----\n");
				check=1;
				if(node==head&&head->next==NULL)
				{
					head=NULL;
					tail=head;
					free(node);
					printf("\n------删除信息成功------\n");
			    }
			 	else if(node==head&&head->next!=NULL)
			 	{
			 		node=head;
			 		head=head->next;
			 		free(node);
			 		printf("\n------删除信息成功-------\n");
			 		n=n-1;
				 }
				 else if(node->next!=NULL)
				 {
				 	p1->next=node->next;
				 	free(node);
				 	printf("\n------删除信息成功-------\n");
				 	n=n-1;
				 }
				  else if(node->next!=NULL)
				 {
				 	p1->next=NULL;
				 	tail=p1;
				 	free(node);
				 	printf("\n------删除信息成功-------\n");
				 	n=n-1;
		 	     }	
				  getchar();
				  return;	
	 			}
	 			else
	 			{
	 				p1=node;
	 				node=node->next;
				 }
	 
		}
	}
	if(head!=NULL&&check==0)
	{
		printf("\n对不起，你要删除的选手信息不存在！\n"); 
	}
	getchar();
}
