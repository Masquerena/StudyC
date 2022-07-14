#include"connection.h"

void menu(void)
{
	printf("********************\n");
	printf("****1.add  2.del****\n");
	printf("****3.rev  4.fin****\n");
	printf("****5.pri  0.exit***\n");
	printf("********************\n");
}

void initialize_contact(contact* con)//初始化通讯录为0
{
	con->data = (connect*) calloc(MAX_SPACE, sizeof(connect));
	if (con->data == NULL)
	{
		perror("initialize_contact");
		printf("增加失败\n");
		return;
	}
	con->sz = 0;
	con->capacity = MAX_SPACE;
	return;
}

void load(contact* con)//录入文件中的数据
{
	FILE* fp = fopen("contact_information.dat", "r");
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}

	connect ect = { 0 };
	while (fread(&ect, sizeof(connect), 1, fp))//录入文件中的数据，fread（）函数会返回它所录入的数据的个数，录入为0时返回0
	{
		if (con->sz == con->capacity)
		{
			place_add(con);
		}
		con->data[con->sz] = ect;
		con->sz++;
	}

	fclose(fp);
	fp = NULL;
	return;
}

void place_add(contact* con)//增加通讯录中的存储空间
{

		connect* ptr = (connect*)realloc(con->data, (con->capacity + INT_ADD) * sizeof(connect));
		if (ptr != NULL)
		{
			con->data = ptr;
			con->capacity += INT_ADD;
			printf("增加空间成功\n");
		}
		else
		{
			perror("increase");
			printf("增加空间失败\n");
			return;
		}
}

void increase(contact* con)//增加通讯录中人的信息
{
	if (con->sz == MAX_DATA)
	{
		printf("增加已达上限，增加失败\n");
		return;
	}

	if (con->sz == con->capacity)
	{
		place_add(con);
	}
	
	printf("请输入名字：");
	scanf("%s", con->data[con->sz].name);
	printf("请输入年龄：");
	scanf("%d", &(con->data[con->sz].age));
	printf("请输入性别：");
	scanf("%s", con->data[con->sz].gender);
	printf("请输入电话：");
	scanf("%s", con->data[con->sz].tel);
	printf("请输入地址：");
	scanf("%s", con->data[con->sz].address);
	con->sz++;
	printf("增加成功\n");
	return;
}

void delete(contact* con)//删除人的信息
{
	if (con->sz == 0)
	{
		printf("通讯录中无信息可删除");
		return;
	}
	char name[MAX_NAME];
	printf("请输入你要删除的人的名字：");
	scanf("%s", name);

	int i = 0;
	int j = 0;
	int subscript[MAX_SUB] = { 0 };

	j = Find(con, name, subscript);

	if (j != 0)
	{
		int input = 0;
		printf("请输入一个数字选择你要删除的联系人：");
		scanf("%d", &input);

		int ch = subscript[input - 1];
		for (ch; ch < con->sz; ch++)
		{
			con->data[ch] = con->data[ch + 1];
		}
		con->sz--;

		connect* ptr = (connect*)realloc(con->data, (con->capacity - 1) * sizeof(connect));//每删除一个联系人信息，就回收一个空间
		con->data = ptr;
		con->capacity -= 1;

		printf("删除成功\n"); 
		return;
	}

	printf("通讯录中无该人\n");
	return;
}

void revise(contact* con)//修改人的信息
{
	if (con->sz == 0)
	{
		printf("通讯录中无可修改信息\n");
		return;
	}
	char name[MAX_NAME];
	printf("请输入你要修改的人的名字：");
	scanf("%s", name);

	int i = 0;
	int j = 0;
	int subscript[MAX_SUB] = { 0 };

	j = Find(con, name, subscript);

	if (j > 0)
	{
		int input = 0;
		printf("请输入一个数字选择你要修改的联系人：");
		scanf("%d", &input);

		int ch = subscript[input - 1];
		printf("请输入修改后的名字：");
		scanf("%s", con->data[ch].name);
		printf("请输入修改后的年龄：");
		scanf("%d", &(con->data[ch].age));
		printf("请输入修改后的性别：");
		scanf("%s", con->data[ch].gender);
		printf("请输入修改后的电话：");
		scanf("%s", con->data[ch].tel);
		printf("请输入修改后的地址：");
		scanf("%s", con->data[ch].address);

		printf("修改成功\n");
		return;
	}
	printf("通讯录中无该人信息\n");
	return;
}

int find(const contact* con, char* name)//寻找人的信息
{
	int i = 0;
	int t = 0;
	int j = 0;
	for (i = 0; i < con->sz; i++)
	{;
		if (strcmp(name, con->data[i].name) == 0)
		{
			j = i;

			if (t == 0)
			{
				printf("已找到\n");
				t++;
			}

			printf("%-20s\t%-5d\t%-5s\t%-15s\t%-20s\n", con->data[i].name, con->data[i].age,
				                                        con->data[i].gender, con->data[i].tel,
				                                        con->data[i].address);
		}
	}
	if (t == 0)
	{
		printf("未找到\n");
		return -1;
	}

	if (i + 1 >= con->sz)
	{
		return j;
	}
}

void print(const contact* con)//打印人的信息
{
	int i = 0;

	printf("%-20s\t%-5s\t%-5s\t%-15s\t%-20s\n","姓名", "年龄", "性别", "电话", "地址");

	for (i = 0; i < (con->sz); i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-15s\t%-20s\n", con->data[i].name, con->data[i].age,
			                                        con->data[i].gender, con->data[i].tel,
			                                        con->data[i].address);
	}
	return;
}

void write(const contact* con)////把记录的通讯录信息录入到文件中
{
	FILE* fp = fopen("contact_information.dat", "w");//以“只读”的形式打开文件
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}

	int i = 0;
	for (i = 0; i < con->sz; i++)//将con->data指向的数据录入到打开的文件中
	{
		fwrite(con->data + i, sizeof(connect), 1, fp);
	}
	
	fclose(fp);//关闭文件
	fp = NULL;
	return;
}

void purge(contact* con)//销毁申请的动态空间
{
	free(con->data);
	con->data = NULL;
	con->sz = 0;
	con->capacity = 0;
	return;
}

int Find(const contact* con, char* name, int* subscript)//供delete()和revise（）函数使用的查找函数
{
	int i = 0;
	int j = 0;

	for (i = 0; i < con->sz; i++)
	{
		if (strcmp(name, con->data[i].name) == 0)
		{
			printf("%-20s\t%-5d\t%-5s\t%-15s\t%-20s\n", con->data[i].name, con->data[i].age,
				con->data[i].gender, con->data[i].tel,
				con->data[i].address);

			subscript[j] = i;
			j++;
		}
	}
	return j;
}