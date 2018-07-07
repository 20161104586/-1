#include "common.h"
#include "seqlist.h"

int  xuanshou(seqlist L,double num)
{
	int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i<=L.last)&&(L.elem[i].num!=num))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
	if  (i<=L.last)
	{
		return(i+1);  /*若找到值为e的元素，则返回其序号*/
	}

	else
	{
		printf("在此线性表中没有该元素!\n");
		return(-1);  /*若没找到，则返回空序号*/

	}
}
int  caipan(seqlist L,double num)
{
	int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i<=L.last2)&&(L.elem2[i].num!=num))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
	if  (i<=L.last2)
	{
		return(i+1);  /*若找到值为e的元素，则返回其序号*/
	}

	else
	{
		printf("在此线性表中没有该元素!\n");
		return(-1);  /*若没找到，则返回空序号*/

	}
}

 
void onput(seqlist *L,int x)
{
    if(x==1)
    {
        printf("----------------------------选手：\n");
        int i,j;
        for(i=0;i<=L->last;i++)
        {
            printf("电话-----------姓名-----性别-----表演名称------表演类别--分数----1------2------3------4------5------6------7------8------9------10-----最后得分\n");
            printf("%-15.0lf",L->elem[i].num);
            printf("%-9s",L->elem[i].name);
            printf("%-9s",L->elem[i].sex);
            printf("%-14s",L->elem[i].play_name);
            printf("%-18s",L->elem[i].play_category);
            for(j=0;j<10;j++)
            {
                printf("%-7.2lf",L->elem[i].score[j]);
            }
            printf("%-7.2lf\n",L->elem[i].score_avg);
        }
    }
    else
    {

        printf("---------------------------裁判：\n");
        int i,j;

        for(i=0;i<=L->last2;i++)
        {
            printf("电话-----------姓名-----性别\n");
            printf("%-15.0lf",L->elem2[i].num);
            printf("%-9s",L->elem2[i].name);
            printf("%-9s\n",L->elem2[i].sex);
        }
    }


}

void input(seqlist *L)
{
	int r,i,j;
    printf("请输入1 存入选手信息: \n");
    printf("请输入2 存入裁判信息: \n");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        printf("有几位选手参加:");
        scanf("%d",&r);
        L->last = r-1;
        for(i=0;i<=L->last;i++)
        {
            L->elem[i].score_max=0;
            L->elem[i].score_min=10;
            L->elem[i].score_sum=0;
            printf("请输入选手各项信息：\n");
            printf("电话：");
            scanf("%lf",&L->elem[i].num);
            printf("姓名：");
            scanf("%s",L->elem[i].name);
            printf("性别：");
            scanf("%s",L->elem[i].sex);
            printf("节目名称：");
            scanf("%s",L->elem[i].play_name);
            printf("节目类别：");
            scanf("%s",L->elem[i].play_category);
            printf("评委打分(%d个)：",L->last2+1);
            for(j=0;j<=L->last2;j++)
            {
                scanf("%lf",&L->elem[i].score[j]);
                if(L->elem[i].score_max<L->elem[i].score[j])
                    L->elem[i].score_max=L->elem[i].score[j];
                if(L->elem[i].score_min>L->elem[i].score[j])
                    L->elem[i].score_min=L->elem[i].score[j];
                L->elem[i].score_sum+=L->elem[i].score[j];
            }
            L->elem[i].score_avg=(L->elem[i].score_sum-L->elem[i].score_max-L->elem[i].score_min)/(L->last2-1);
        }
        onput(L,x);
    }
    else
    {
        printf("有几位评委:");
        scanf("%d",&r);

        L->last2 = r-1;
        printf("请输入评委的信息:\n");
        for(i=0; i<=r-1; i++)
        {
            printf("电话: ");
            scanf("%lf",&L->elem2[i].num);
            printf("姓名: ");
            scanf("%s",L->elem2[i].name);
            printf("性别: ");
            scanf("%s",L->elem2[i].sex);
        }
        onput(L,x);
    }
}

void look(seqlist *L)
{
	int temp,x,i,j;
	double q;
	printf("输入1 查找选手：\n");
	printf("输入2 查找裁判：\n");
	scanf("%d",&x);
	if(x==1)
    {
        printf("输入要查找选手的电话:\n");
        scanf("%lf",&q);
        temp=xuanshou(*L,q)-1;
        if(temp!=-1)
        {
            printf("电话-----------姓名-----性别-----表演名称-----表演类别--分数----1------2------3------4------5------6------7------8------9------10-----最后得分\n");
            printf("%-15.0lf",L->elem[temp].num);
            printf("%-9s",L->elem[temp].name);
            printf("%-9s",L->elem[temp].sex);
            printf("%-14s",L->elem[temp].play_name);
            printf("%-18s",L->elem[temp].play_category);
            for(j=0;j<=L->last2;j++)
            {
                printf("%-7.2lf",L->elem[temp].score[j]);
            }
            printf("%-7.2lf\n",L->elem[temp].score_avg);
        }
    }
    else
    {
        printf("请输入要查找的评委电话:\n");
        scanf("%lf",&q);
        temp=caipan(*L,q)-1;
        if(temp!=-1)
        {
            printf("电话-----------姓名-----性别\n");
            printf("%-15.0lf",L->elem[temp].num);
            printf("%-9s",L->elem[temp].name);
            printf("%-9s",L->elem[temp].sex);
        }
    }

}

void Updata(seqlist *L)
{
    int i,q;
    int x;
    double tem;
	printf("输入1 查找选手：\n");
	printf("输入2 查找裁判：\n");
	scanf("%d",&x);
	if(x==1)
    {
       printf("请输入要修改的电话：\n");
        scanf("%lf",&tem);
        q=xuanshou(*L,tem);
        if(q==-1)
        {
            printf("你要修改的元素不存在！\n");
            return ;
        }
        else
        {
            L->elem[q-1].score_max=0;
            L->elem[q-1].score_sum=0;
            L->elem[q-1].score_min=10;
            printf("请输入除去电话以外的信息:\n");
            printf("姓名: ");
            scanf("%s",L->elem[q-1].name);
            printf("性别: ");
            scanf("%s",L->elem[q-1].sex);
            printf("节目名称: ");
            scanf("%s",L->elem[q-1].play_name);
            printf("节目种类: ");
            scanf("%s",L->elem[q-1].play_category);
            printf("评委分数(%d个): ",L->last2+1);
            for(i=0;i<=L->last2;i++)
            {
                scanf("%lf",&L->elem[q-1].score[i]);
                if(L->elem[q-1].score_max<L->elem[q-1].score[i])
                    L->elem[q-1].score_max=L->elem[q-1].score[i];
                if(L->elem[q-1].score_min>L->elem[q-1].score[i])
                    L->elem[q-1].score_min=L->elem[q-1].score[i];
                L->elem[q-1].score_sum+=L->elem[q-1].score[i];
            }
            L->elem[q-1].score_avg=(L->elem[q-1].score_sum-L->elem[q-1].score_max-L->elem[q-1].score_min)/L->last2-1;
            printf("信息修改完成！\n");
        }
    }
    else
    {
        printf("请输入要修改人的电话：\n");
        scanf("%lf",&tem);
        q=caipan(*L,tem);
        if(q==-1)
        {
            printf("你要修改的元素不存在！\n");
            return ;
        }
        else
        {
            printf("请输入除去电话以外的信息:\n");
            printf("姓名: ");
            scanf("%s",L->elem2[q-1].name);
            printf("性别: ");
            scanf("%s",L->elem2[q-1].sex);
            printf("信息修改完成！\n");
        }
    }

}

void Delete(seqlist *L)
{
	int j;
	int i,x;
	double q;
	printf("输入1 查找选手：");
	printf("输入2 查找裁判：");
	scanf("%d",&x);
	if(x==1)
    {
        printf("请输入要删除的元素:\n");
        scanf("%lf",&q);
        i=xuanshou(*L,q);

        if(i<1)
        {
            return ;
        }
        else
        {
            for(j=i;j<=L->last;j++)
            L->elem[j-1]=L->elem[j];
            L->last--;
            printf("位序为%d的元素已经删除\n",i);
            onput(L,x);
        }
    }
    else
    {
        printf("请输入要删除的元素:\n");
        scanf("%lf",&q);
        i=caipan(*L,q);

        if(i<1)
        {
            return ;
        }
        else
        {
            for(j=i;j<=L->last2;j++)
            L->elem2[j-1]=L->elem2[j];
            L->last2--;
            printf("位序为%d的元素已经删除\n",i);
            onput(L,x);
        }
    }
}

int Insert(seqlist *L)
{
	ElemType x1;
	memset(x1.score,0,sizeof(x1.score));
	ElemType2 x2;
	int i;
 	printf("输入1 插入选手：");
	printf("输入2 插入裁判：");
    int w;
    scanf("%d",&w);
    if(w==1)
    {
        x1.score_max=0;
        x1.score_min=10;
        x1.score_sum=0;
        printf("请输入选手的信息:\n");
        printf("电话: ");
        scanf("%lf",&x1.num);
        int temp;
        temp=xuanshou(*L,x1.num);
        if(temp==-1)
        {
            printf("你输入的号码重复!请重新操作\n");
            return ;
        }
        printf("姓名: ");
        scanf("%s",x1.name);
        printf("性别: ");
        scanf("%s",x1.sex);
        printf("节目名称: ");
        scanf("%s",x1.play_name);
        printf("节目类别: ");
        scanf("%s",x1.play_category);
        printf("请输入选手的%d门分数: ",L->last2+1);
        for(i=0;i<=L->last2;i++)
        {
            scanf("%lf",&x1.score[i]);
            if(x1.score_max<x1.score[i])
                x1.score_max=x1.score[i];
            if(x1.score_min>x1.score[i])
                x1.score_min=x1.score[i];
            x1.score_sum+=x1.score[i];
        }
        x1.score_avg=(x1.score_sum-x1.score_max-x1.score_min)/L->last2-1;
        printf("信息录入完成！\n");
        printf("请输入要插入的元素的位置:\n");
        scanf("%d",&i);

        int j;

        if(L->last==MAXSIZE-1)
        {
            printf(" 表满\n");
            return 0;
        }
        if(i<1||i>L->last+2)
        {
            printf("位序不合法\n");
            return 0;
        }
        for(j=L->last;j>=i-1;j--)
            L->elem[j+1]=L->elem[j];
        L->elem[i-1]=x1;
        L->last++;
        onput(L,1);
        return 1;
    }
    else
    {
        printf("请输入要插入的元素:\n");
        printf("电话: ");
        scanf("%lf",&x2.num);
        int temp;
        temp=caipan(*L,x2.num);
        if(temp==-1)
        {
            printf("你输入的号码重复!,请重新操作\n");
            return ;
        }
        printf("姓名: ");
        scanf("%s",x2.name);
        printf("性别: ");
        scanf("%s",x2.sex);
        printf("信息录入完成！\n");
        printf("请输入要插入的元素的位置:\n");
        scanf("%d",&i);

        int j;

        if(L->last2==MAXSIZE-1)
        {
            printf(" 表满\n");
            return 0;
        }
        if(i<1||i>L->last2+2)
        {
            printf("位序不合法\n");
            return 0;
        }
        for(j=L->last2;j>=i-1;j--)
            L->elem2[j+1]=L->elem2[j];
        L->elem2[i-1]=x2;
        L->last2++;
        onput(L,2);
        return 1;
    }

}


void swap(ElemType *a, ElemType *b)
{
    ElemType temp;

    temp = *a;
    *a = *b;
    *b = temp;

    return ;
}

void quicksort(ElemType array[], int maxlen, int begin, int end)
{
    int i, j;

    if(begin < end)
    {
        i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！
        j = end;        // array[end]是数组的最后一位

        while(i < j)
        {
            if(array[i].score_avg > array[begin].score_avg)  // 如果比较的数组元素大于基准数，则交换位置。
            {
                swap(&array[i], &array[j]);  // 交换两个数
                j--;
            }
            else
            {
                i++;  // 将数组向后移一位，继续与基准数比较。
            }
        }

        /* 跳出while循环后，i = j。
         * 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin]
         *                           -->  array[i+1] ~ array[end] > array[begin]
         * 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。
         * 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
         */

        if(array[i].score_avg >= array[begin].score_avg)  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
        {
            i--;
        }

        swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]

        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}





void save(seqlist *L)
{
    FILE *fp;
    fp=fopen("选手信息.csv","a+");
    if(fp==NULL)
    {
        printf("文件打开失败！数据无法保存！\n");
        return ;
    }
    int i,j;
    fprintf(fp,"电话,姓名,性别,表演名称,表演类别,分数,1,2,3,4,5,6,7,8,9,10,最后得分\n");
    for(i=0;i<=L->last;i++)
    {
        fprintf(fp,"%.0lf,",L->elem[i].num);
        fprintf(fp,"%s,",L->elem[i].name);
        fprintf(fp,"%s,",L->elem[i].sex);
        fprintf(fp,"%s,",L->elem[i].play_name);
        fprintf(fp,"%s,",L->elem[i].play_category);
        for(j=0;j<10;j++)
        {
            fprintf(fp,"%.2lf,",L->elem[i].score[j]);
        }
        fprintf(fp,"%-2lf\n",L->elem[i].score_avg);
    }
	printf("文件成功保存到学生信息.csv中\n");
	fp=fopen("裁判信息.csv","a+");
    if(fp==NULL)
    {
        printf("文件打开失败！数据无法保存！\n");
        return ;
    }
    fprintf(fp,"电话,姓名,性别\n");
    for(i=0;i<=L->last2;i++)
        {
            fprintf(fp,"%.0lf,",L->elem2[i].num);
            fprintf(fp,"%s,",L->elem2[i].name);
            fprintf(fp,"%s\n",L->elem2[i].sex);
        }
	printf("文件成功保存到裁判信息.csv中\n");
}

void login(seqlist *L)
{
    char file_name[] = "选手信息.csv";
    FILE *fp;
    fp = fopen("选手信息.csv", "a+");


    char line[MAX_LINE_SIZE];
    char *result = NULL;

    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) 
	{
        result = strtok(line, ",");
        int i = 0;
        while( result != NULL )
		{

            if(i!=0)
			{
                printf("%d\t", atoi(result));
            }

            else
			{
                printf("%s\t", result);
                i++;
            }
            result = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose (fp);
   

}

void sort2(seqlist *L)
{
    quicksort(L->elem, L->last+1, 0, L->last);
    onput(L,1);
}

void mean()
{
	seqlist l;
	int t;
	while(1)
	{
		printf("******************************\n");
		printf("|--------------------------|\n");
		printf("|   选手信息管理           |\n");
		printf("|    [1]存入信息        |\n");
		printf("|    [2]查询信息             |\n");
		printf("|    [3]插入信息             |\n");
		printf("|    [4]修改选手信息         |\n");
		printf("|    [5]删除选手信息         |\n");
		printf("|    [6]选手分数排序         |\n");
		printf("|    [7]输出所有信息     |\n");
		printf("|    [8]读取文件             |\n");
		printf("|    [9]退出并保存           |\n");
		printf("|--------------------------|\n");

		printf("请输入1-9:");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : input(&l); break;
			case 2 : look(&l); break;
			case 3 : Insert(&l); break;
			case 4 : Updata(&l); break;
			case 5 : Delete(&l); break;
			case 6 : sort2(&l); break;
			case 7 : onput(&l,1);onput(&l,2); break;
			case 8 : login(&l); break;
			case 9 : save(&l); exit(0);
			
			 default:
            printf("您输入的菜单有误。请重新输入！\n");

		}
	}

}

void main()
{
	mean();
}
