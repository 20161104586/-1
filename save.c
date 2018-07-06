#include "com.h" 
void save(int n) 
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
