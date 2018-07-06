#include "com.h" 
#include "seq.h"
int main(void)
{
    int choice,n;
    while (1)
    {
        printf("*************************************\n");
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
        printf("请输入您的选择（0 - 7）:");
        scanf("%d",&choice);
        printf("**************************************)\n");

        switch (choice)
        {
	 	case 1:
	 	    printf("请输入录入的信息数： ");
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
        case 7://退出程序 
            printf("退出程序\n");
            printf("程序结束，谢谢使用!\n");
            exit(0);

        default:
            printf("您输入的菜单有误。请重新输入！\n");

        }

    }
    return 0;
}

