#include "com.h" 
void del(int n)
{
	S_MESSAGE*node=(S_MESSAGE*)malloc(LEN); 
	S_MESSAGE*p1; 
	int check=0;
	long del_num;
	printf("\n������Ҫɾ����ѡ�ֵı��:");
	scanf("%d",&del_num);
	if(head==NULL&&tail==NULL)
	{
		printf("\n��ǰ��Ϣ��¼Ϊ��,ɾ��ʧ�ܣ�\n");
	 } 
	 else
	 {
	 	node=head;
	 	p1=head;
	 	while(node!=NULL)
	 	{
	 		if(node->num==del_num)
	 		{
	 			printf("\n------Ҫɾ����ѡ����Ϣ-----\n");
	 			printf("------|-----\n");
				printf("���|����\n");
				printf("------|-----\n");
				printf("%-9d%-6s\n",node->num,node->name); 
				printf("------|-----\n");
				check=1;
				if(node==head&&head->next==NULL)
				{
					head=NULL;
					tail=head;
					free(node);
					printf("\n------ɾ����Ϣ�ɹ�------\n");
			    }
			 	else if(node==head&&head->next!=NULL)
			 	{
			 		node=head;
			 		head=head->next;
			 		free(node);
			 		printf("\n------ɾ����Ϣ�ɹ�-------\n");
			 		n=n-1;
				 }
				 else if(node->next!=NULL)
				 {
				 	p1->next=node->next;
				 	free(node);
				 	printf("\n------ɾ����Ϣ�ɹ�-------\n");
				 	n=n-1;
				 }
				  else if(node->next!=NULL)
				 {
				 	p1->next=NULL;
				 	tail=p1;
				 	free(node);
				 	printf("\n------ɾ����Ϣ�ɹ�-------\n");
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
		printf("\n�Բ�����Ҫɾ����ѡ����Ϣ�����ڣ�\n"); 
	}
	getchar();
}
