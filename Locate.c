#include "common.h"
#include "seqlist.h"

int  xuanshou(seqlist L,double num)
{
	int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i<=L.last)&&(L.elem[i].num!=num))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++;
	if  (i<=L.last)
	{
		return(i+1);  /*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
	}

	else
	{
		printf("�ڴ����Ա���û�и�Ԫ��!\n");
		return(-1);  /*��û�ҵ����򷵻ؿ����*/

	}
}
int  caipan(seqlist L,double num)
{
	int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i<=L.last2)&&(L.elem2[i].num!=num))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++;
	if  (i<=L.last2)
	{
		return(i+1);  /*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
	}

	else
	{
		printf("�ڴ����Ա���û�и�Ԫ��!\n");
		return(-1);  /*��û�ҵ����򷵻ؿ����*/

	}
}

 
void onput(seqlist *L,int x)
{
    if(x==1)
    {
        printf("----------------------------ѡ�֣�\n");
        int i,j;
        for(i=0;i<=L->last;i++)
        {
            printf("�绰-----------����-----�Ա�-----��������------�������--����----1------2------3------4------5------6------7------8------9------10-----���÷�\n");
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

        printf("---------------------------���У�\n");
        int i,j;

        for(i=0;i<=L->last2;i++)
        {
            printf("�绰-----------����-----�Ա�\n");
            printf("%-15.0lf",L->elem2[i].num);
            printf("%-9s",L->elem2[i].name);
            printf("%-9s\n",L->elem2[i].sex);
        }
    }


}

void input(seqlist *L)
{
	int r,i,j;
    printf("������1 ����ѡ����Ϣ: \n");
    printf("������2 ���������Ϣ: \n");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        printf("�м�λѡ�ֲμ�:");
        scanf("%d",&r);
        L->last = r-1;
        for(i=0;i<=L->last;i++)
        {
            L->elem[i].score_max=0;
            L->elem[i].score_min=10;
            L->elem[i].score_sum=0;
            printf("������ѡ�ָ�����Ϣ��\n");
            printf("�绰��");
            scanf("%lf",&L->elem[i].num);
            printf("������");
            scanf("%s",L->elem[i].name);
            printf("�Ա�");
            scanf("%s",L->elem[i].sex);
            printf("��Ŀ���ƣ�");
            scanf("%s",L->elem[i].play_name);
            printf("��Ŀ���");
            scanf("%s",L->elem[i].play_category);
            printf("��ί���(%d��)��",L->last2+1);
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
        printf("�м�λ��ί:");
        scanf("%d",&r);

        L->last2 = r-1;
        printf("��������ί����Ϣ:\n");
        for(i=0; i<=r-1; i++)
        {
            printf("�绰: ");
            scanf("%lf",&L->elem2[i].num);
            printf("����: ");
            scanf("%s",L->elem2[i].name);
            printf("�Ա�: ");
            scanf("%s",L->elem2[i].sex);
        }
        onput(L,x);
    }
}

void look(seqlist *L)
{
	int temp,x,i,j;
	double q;
	printf("����1 ����ѡ�֣�\n");
	printf("����2 ���Ҳ��У�\n");
	scanf("%d",&x);
	if(x==1)
    {
        printf("����Ҫ����ѡ�ֵĵ绰:\n");
        scanf("%lf",&q);
        temp=xuanshou(*L,q)-1;
        if(temp!=-1)
        {
            printf("�绰-----------����-----�Ա�-----��������-----�������--����----1------2------3------4------5------6------7------8------9------10-----���÷�\n");
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
        printf("������Ҫ���ҵ���ί�绰:\n");
        scanf("%lf",&q);
        temp=caipan(*L,q)-1;
        if(temp!=-1)
        {
            printf("�绰-----------����-----�Ա�\n");
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
	printf("����1 ����ѡ�֣�\n");
	printf("����2 ���Ҳ��У�\n");
	scanf("%d",&x);
	if(x==1)
    {
       printf("������Ҫ�޸ĵĵ绰��\n");
        scanf("%lf",&tem);
        q=xuanshou(*L,tem);
        if(q==-1)
        {
            printf("��Ҫ�޸ĵ�Ԫ�ز����ڣ�\n");
            return ;
        }
        else
        {
            L->elem[q-1].score_max=0;
            L->elem[q-1].score_sum=0;
            L->elem[q-1].score_min=10;
            printf("�������ȥ�绰�������Ϣ:\n");
            printf("����: ");
            scanf("%s",L->elem[q-1].name);
            printf("�Ա�: ");
            scanf("%s",L->elem[q-1].sex);
            printf("��Ŀ����: ");
            scanf("%s",L->elem[q-1].play_name);
            printf("��Ŀ����: ");
            scanf("%s",L->elem[q-1].play_category);
            printf("��ί����(%d��): ",L->last2+1);
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
            printf("��Ϣ�޸���ɣ�\n");
        }
    }
    else
    {
        printf("������Ҫ�޸��˵ĵ绰��\n");
        scanf("%lf",&tem);
        q=caipan(*L,tem);
        if(q==-1)
        {
            printf("��Ҫ�޸ĵ�Ԫ�ز����ڣ�\n");
            return ;
        }
        else
        {
            printf("�������ȥ�绰�������Ϣ:\n");
            printf("����: ");
            scanf("%s",L->elem2[q-1].name);
            printf("�Ա�: ");
            scanf("%s",L->elem2[q-1].sex);
            printf("��Ϣ�޸���ɣ�\n");
        }
    }

}

void Delete(seqlist *L)
{
	int j;
	int i,x;
	double q;
	printf("����1 ����ѡ�֣�");
	printf("����2 ���Ҳ��У�");
	scanf("%d",&x);
	if(x==1)
    {
        printf("������Ҫɾ����Ԫ��:\n");
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
            printf("λ��Ϊ%d��Ԫ���Ѿ�ɾ��\n",i);
            onput(L,x);
        }
    }
    else
    {
        printf("������Ҫɾ����Ԫ��:\n");
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
            printf("λ��Ϊ%d��Ԫ���Ѿ�ɾ��\n",i);
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
 	printf("����1 ����ѡ�֣�");
	printf("����2 ������У�");
    int w;
    scanf("%d",&w);
    if(w==1)
    {
        x1.score_max=0;
        x1.score_min=10;
        x1.score_sum=0;
        printf("������ѡ�ֵ���Ϣ:\n");
        printf("�绰: ");
        scanf("%lf",&x1.num);
        int temp;
        temp=xuanshou(*L,x1.num);
        if(temp==-1)
        {
            printf("������ĺ����ظ�!�����²���\n");
            return ;
        }
        printf("����: ");
        scanf("%s",x1.name);
        printf("�Ա�: ");
        scanf("%s",x1.sex);
        printf("��Ŀ����: ");
        scanf("%s",x1.play_name);
        printf("��Ŀ���: ");
        scanf("%s",x1.play_category);
        printf("������ѡ�ֵ�%d�ŷ���: ",L->last2+1);
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
        printf("��Ϣ¼����ɣ�\n");
        printf("������Ҫ�����Ԫ�ص�λ��:\n");
        scanf("%d",&i);

        int j;

        if(L->last==MAXSIZE-1)
        {
            printf(" ����\n");
            return 0;
        }
        if(i<1||i>L->last+2)
        {
            printf("λ�򲻺Ϸ�\n");
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
        printf("������Ҫ�����Ԫ��:\n");
        printf("�绰: ");
        scanf("%lf",&x2.num);
        int temp;
        temp=caipan(*L,x2.num);
        if(temp==-1)
        {
            printf("������ĺ����ظ�!,�����²���\n");
            return ;
        }
        printf("����: ");
        scanf("%s",x2.name);
        printf("�Ա�: ");
        scanf("%s",x2.sex);
        printf("��Ϣ¼����ɣ�\n");
        printf("������Ҫ�����Ԫ�ص�λ��:\n");
        scanf("%d",&i);

        int j;

        if(L->last2==MAXSIZE-1)
        {
            printf(" ����\n");
            return 0;
        }
        if(i<1||i>L->last2+2)
        {
            printf("λ�򲻺Ϸ�\n");
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
        i = begin + 1;  // ��array[begin]��Ϊ��׼������˴�array[begin+1]��ʼ���׼���Ƚϣ�
        j = end;        // array[end]����������һλ

        while(i < j)
        {
            if(array[i].score_avg > array[begin].score_avg)  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
            {
                swap(&array[i], &array[j]);  // ����������
                j--;
            }
            else
            {
                i++;  // �����������һλ���������׼���Ƚϡ�
            }
        }

        /* ����whileѭ����i = j��
         * ��ʱ���鱻�ָ����������  -->  array[begin+1] ~ array[i-1] < array[begin]
         *                           -->  array[i+1] ~ array[end] > array[begin]
         * ���ʱ������array�ֳ��������֣��ٽ�array[i]��array[begin]���бȽϣ�����array[i]��λ�á�
         * ���array[i]��array[begin]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���
         */

        if(array[i].score_avg >= array[begin].score_avg)  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
        {
            i--;
        }

        swap(&array[begin], &array[i]);  // ����array[i]��array[begin]

        quicksort(array, maxlen, begin, i);
        quicksort(array, maxlen, j, end);
    }
}





void save(seqlist *L)
{
    FILE *fp;
    fp=fopen("ѡ����Ϣ.csv","a+");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷����棡\n");
        return ;
    }
    int i,j;
    fprintf(fp,"�绰,����,�Ա�,��������,�������,����,1,2,3,4,5,6,7,8,9,10,���÷�\n");
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
	printf("�ļ��ɹ����浽ѧ����Ϣ.csv��\n");
	fp=fopen("������Ϣ.csv","a+");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ������޷����棡\n");
        return ;
    }
    fprintf(fp,"�绰,����,�Ա�\n");
    for(i=0;i<=L->last2;i++)
        {
            fprintf(fp,"%.0lf,",L->elem2[i].num);
            fprintf(fp,"%s,",L->elem2[i].name);
            fprintf(fp,"%s\n",L->elem2[i].sex);
        }
	printf("�ļ��ɹ����浽������Ϣ.csv��\n");
}

void login(seqlist *L)
{
    char file_name[] = "ѡ����Ϣ.csv";
    FILE *fp;
    fp = fopen("ѡ����Ϣ.csv", "a+");


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
		printf("|   ѡ����Ϣ����           |\n");
		printf("|    [1]������Ϣ        |\n");
		printf("|    [2]��ѯ��Ϣ             |\n");
		printf("|    [3]������Ϣ             |\n");
		printf("|    [4]�޸�ѡ����Ϣ         |\n");
		printf("|    [5]ɾ��ѡ����Ϣ         |\n");
		printf("|    [6]ѡ�ַ�������         |\n");
		printf("|    [7]���������Ϣ     |\n");
		printf("|    [8]��ȡ�ļ�             |\n");
		printf("|    [9]�˳�������           |\n");
		printf("|--------------------------|\n");

		printf("������1-9:");
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
            printf("������Ĳ˵��������������룡\n");

		}
	}

}

void main()
{
	mean();
}
