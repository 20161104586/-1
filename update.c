#include "com.h" 
void update(int n)
{
	S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN); 
	int check=0;
	long updatenum;
	printf("\n������Ҫ�޸ĵ�ѡ�ֱ�ţ�");
	scanf("%d",&updatenum);
	if(head==NULL&&tail==NULL)
	{
		printf("\n------��ǰ��Ϣ��¼Ϊ��-----\n");
	} 
	else
	{
		while(p1!=NULL)
		{
			if(p1->num==updatenum)
			{
				printf("\n------��Ҫ�޸ĵ�ѡ����Ϣ����-----\n");
				printf("------|-----\n");
				printf("���|����\n");
				printf("------|-----\n");
				printf("%-9d%-6s\n",p1->num,p1->name); 
				printf("------|-----\n");
				printf("\n------������д���ѡ����Ϣ��-----\n");
				check=1;
				printf("\n�޸�ѡ�ֱ��Ϊ��");
				scanf("%d",&p1->num);
				printf("\n�޸�ѡ������Ϊ��");
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
		printf("\n�Բ�����Ҫ�޸ĵ�ѡ����Ϣ�����ڣ�\n");
	}
	getchar();
	
}

