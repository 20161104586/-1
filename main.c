#include "com.h" 
#include "seq.h"
int main(void)
{
    int choice,n;
    while (1)
    {
        printf("*************************************\n");
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
        printf("����������ѡ��0 - 7��:");
        scanf("%d",&choice);
        printf("**************************************)\n");

        switch (choice)
        {
	 	case 1:
	 	    printf("������¼�����Ϣ���� ");
            scanf("%d",&n); 
	 		browse(n);
	 		break;
	 	case 2:
	 		creat(n);
	 		break;
	 	case 3:
	 		save(n);
	 		break;
		case 4:
	 		search(n);
	 		break;
		case 5:
	 		update(n);
	 		break;
	 	case 6:
	 		del(n);
	 		break;
        case 7://�˳����� 
            printf("�˳�����\n");
            printf("���������ллʹ��!\n");
            exit(0);

        default:
            printf("������Ĳ˵��������������룡\n");

        }

    }
    return 0;
}

