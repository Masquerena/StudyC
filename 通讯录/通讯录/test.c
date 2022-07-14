#define  _CRT_SECURE_NO_WARNINGS 1
#include"connection.h"

//写一个通讯录，通讯录中能存放1000个人信息
//每个人的信息：
//名字+年龄+性别+电话+地址
//功能：
//增加人的信息
//删除指定人的信息
//修改指定人的信息
//查找指定人的信息
//排序通讯录的信息

int main(void)
{
	contact con;//建立通讯录
	int choose = 0;
	initialize_contact(&con);//初始化通讯录
	load(&con);//录入文件中的数据

	do 
	{
		menu();
		printf("请输入数字选择要进行的操作：");
		scanf("%d", &choose);

		switch (choose)
		{
		case ADD://增加
			increase(&con);
			break;
		case DEL://删除
			delete(&con);
			break;
		case REV://修改
			revise(&con);
			break;
		case FIN://寻找
			printf("请输入你要查找的人的名字：");

			char Name[MAX_NAME] = "0";
			scanf("%s", Name);

			find(&con, Name);
			break;
		case PRI://打印
			print(&con);
			break;
		case EXIT://退出
			write(&con);//把通讯录中的信息记录到文件中
			purge(&con);//销毁申请的动态空间
			printf("程序结束");
			break;
		default:
			printf("输入内容错误，请重新输入\n");
		}
	} while (choose);
	
	return 0;
}