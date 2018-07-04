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
		printf("\n-------当前信息记录为空-------\n"); 
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
	printf("\n--------选手成绩排名信息如下-------\n"); 
	printf("-------|-------|-------|--------\n"); 
	printf(" 编号| 姓名 | 平均成绩| 名次 \n"); 
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


void search() 
{ 
	int c; 
	printf("\n请选择查询内容：\n"); 
	printf("1.选手详细成绩查询  2.选手排名查询\n 输入你的选择： "); 
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
	fp=fopen("参赛选手名单.txt","a+"); 
	fprintf(fp,"-------|-------\n"); 
	fprintf(fp,"编号|姓名\n"); 
	while(p1!=NULL) 
	{ 
		fprintf(fp,"-------|-------\n"); 
		fprintf(fp,"%-9d%-6s\n",p1->num,p1->name); 
		p1=p1->next; 
	} 
	fprintf(fp,"---------|-------\n"); 
	fclose(fp); 
	printf("\n\t文件已将保持到\"参赛选手名单.txt\""); 
} 

void update()
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

void del()
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


void creat() 
{ 
	int i,j; 
	float t; 
	char c='y'; 
	while(c=='y'||c=='Y') 


 	{ 
		S_MESSAGE*p1=(S_MESSAGE*)malloc(LEN); 
		printf("\n 请输入要录入的选手信息：\n"); 
		printf("\n 选手编号："); 
		scanf("%d",&p1->num); 
		
		printf("\n选手姓名:");
		scanf("%s",p1->name);
		printf("\n请输入7位评委点评成绩；");
		
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
				printf("\n内存分配失败\n");
				n=n-1;
				
			}
			if(head==NULL&&tail==NULL)
			{
				head=p1;
				head->next=NULL;
				tail=head;
				printf("\n-----选手信息录入成功-----\n");
			}
			else
			{
				tail->next=p1;
				tail=p1;
				tail->next=NULL;
				printf("\n------选手信息录入成功-----\n");
			}
			printf("是否继续(Y/N):");
			getchar();
			scanf("%c",&c);
	} 
 } 
 
 void quit()
{
 	printf("*************************************\n");
    printf("欢迎使用比赛评分系统\n");
} 

void menu()
{
	printf("\n\n\t***比赛评分系统****\n\n");
	printf("[1] 选手信息浏览\n");
        printf("[2] 选手信息录入\n");
        printf("[3] 选手信息保存\n");
        printf("[4] 选手成绩查询\n");
        printf("[5] 选手信息修改\n");
        printf("[6] 选手信息删除\n");
        printf("[7] 退出系统\n");
        printf("\n*******菜单选择界面*******\n");
        printf("请输入你的选择：");
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
 			printf("你的输入有误，请重新输入:");
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
	
		printf("\n欢迎进入\n");
		plus();

}



