#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#include<string.h> 
#include<malloc.h> 
#define LEN sizeof(S_MESSAGE)  
#define N 7 
typedef struct songer 
{ 
	long num; 
	char name[20]; 
	float grades[N]; 
	double ave; 
	struct songer*next; 
}S_MESSAGE; 
S_MESSAGE*head; 
S_MESSAGE*tail; 
int n=0; 
void creat(); 
void del(); 
void search(); 
void print(); 
void rank(); 
void update(); 
void menu(); 
void menu_select(); 
void browse(); 
void save(); 
void quit(); 

void rank() 
{ 
	S_MESSAGE*p1,*p2,*endpt,*p; 
	n=0; 
	p1=head; 
	if(head==NULL&&tail==NULL) 
	{ 
		printf("\n-------��ǰ��Ϣ��¼Ϊ��-------\n"); 
	} 
	else 
	{ 
		p1=(S_MESSAGE*)malloc(LEN); 
		p1->next=head; 
		head=p1; 
		for(endpt=NULL;endpt!=head;endpt=p) 
	{ 
			for(p=p1=head;p1->next->next!=endpt;p1=p1->next) 
				{ 
					if(p1->next->ave<p1->next->next->ave) 
					{ 
					p2=p1->next->next; 
						p1->next->next=p2->next; 
						p2->next=p1->next; 
						p1->next=p2; 
						p=p1->next->next; 
					} 
				}		 
	} 
	p1=head; 
	head=head->next; 
	free(p1); 
	printf("\n--------ѡ�ֳɼ�������Ϣ����-------\n"); 
	printf("-------|-------|-------|--------\n"); 
	printf(" ���| ���� | ƽ���ɼ�| ���� \n"); 
	p1=head; 
	while(p1!=NULL) 
		{ 
			printf("-------|-------|-------|--------\n"); 
			printf("%-9d%-9s%-9.1lf%-5d\n",p1->name,p1->name,p1->ave,n+1); 
			n++; 
			p1=p1->next; 
		} 
			printf("-------|-------|-------|--------\n"); 
	} 
		getchar(); 
} 


void print() 
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


void search() 
{ 
	int c; 
	printf("\n��ѡ���ѯ���ݣ�\n"); 
	printf("1.ѡ����ϸ�ɼ���ѯ  2.ѡ��������ѯ\n �������ѡ�� "); 
	scanf("%d",&c); 
	switch(c) 
	{ 
		case 1:system("cls");print();break; 
		case 2:system("cls");rank();break; 
	}  
} 


void save() 
{ 
	FILE*fp; 
	S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN); 
	p1=head; 
	fp=fopen("����ѡ������.txt","a+"); 
	fprintf(fp,"-------|-------\n"); 
	fprintf(fp,"���|����\n"); 
	while(p1!=NULL) 
	{ 
		fprintf(fp,"-------|-------\n"); 
		fprintf(fp,"%-9d%-6s\n",p1->num,p1->name); 
		p1=p1->next; 
	} 
	fprintf(fp,"---------|-------\n"); 
	fclose(fp); 
	printf("\n\t�ļ��ѽ����ֵ�\"����ѡ������.txt\""); 
} 

void update()
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

void del()
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


void creat() 
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
 
 void quit()
{
 	printf("*************************************\n");
    printf("��ӭʹ�ñ�������ϵͳ\n");
} 

void menu()
{
	printf("\n\n\t***��������ϵͳ****\n\n");
	printf("[1] ѡ����Ϣ���\n");
        printf("[2] ѡ����Ϣ¼��\n");
        printf("[3] ѡ����Ϣ����\n");
        printf("[4] ѡ�ֳɼ���ѯ\n");
        printf("[5] ѡ����Ϣ�޸�\n");
        printf("[6] ѡ����Ϣɾ��\n");
        printf("[7] �˳�ϵͳ\n");
        printf("\n*******�˵�ѡ�����*******\n");
        printf("���������ѡ��");
 } 
 
 void menu_select()
 {
 	char s[100];
 	int c;
 	gets(s);
 	while(1)
 	{
 		c=atoi(s);
 		if(c<1||c>7)
 		{
 			printf("���������������������:");
 			gets(s);
		 }
		 else break;
	 }
	 switch(c)
	 {
	 	case1:
	 		system("cls");
	 		browse();
	 		break;
	 	case2:
	 		system("cls");
	 		creat();
	 		break;
	 	case3:
	 		system("cls");
	 		save();
	 		break;
		case4:
	 		system("cls");
	 		search();
	 		break;
		case5:
	 		system("cls");
	 		update();
	 		break;
	 	case6:
	 		system("cls");
	 		del();
	 		break;
		case7:
	 		system("cls");
	 		quit();
	 		return;
	 		break;
	 	default:
	 		break;
	 }
	 getchar();
	 system("cls");
	 menu();
	 menu_select();
} 

int plus()
{
	menu();
	menu_select();
	return 0;
}

int main(void)
{
	
		printf("\n��ӭ����\n");
		plus();

}



