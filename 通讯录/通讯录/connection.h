#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum number
{
	MAX_NAME = 20,
	MAX_GENDER = 5,
	MAX_TEL = 15,
	MAX_ADD = 20,
	MAX_DATA = 1000,
	MAX_SUB = 100
};

enum memory
{
	MAX_SPACE = 3,
	INT_ADD = 2
};

typedef struct connect//名字+年龄+性别+电话+地址
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tel[MAX_TEL];
	char address[MAX_ADD];
}connect;

typedef struct contact
{
	connect* data;//指向申请的动态内存空间
	int sz;//记录通讯录中的联系人个数
	int capacity;//通讯录中的容量
}contact;

enum choose
{
	EXIT,
	ADD,
	DEL,
	REV,
	FIN,
	PRI
};

void menu(void);

void initialize_contact(contact* con);//将通讯录初始化为0

void load(contact* con);//录入文件中的数据

void place_add(contact* con);//增加空间

void increase(contact* con);//增加人的信息

void delete(contact* con);//删除人的信息

void revise(contact* con);//修改人的信息

int find(const contact* con, char* name);//查找人的信息，返回查找到的人的次数

void print(const contact* con);//打印人的信息

void write(const contact* con);//把记录的通讯录信息录入到文件中

void purge(contact* con);//销毁申请的动态空间

int Find(const contact* con, char* name, int* subscript);//供delete（）和revise（）函数使用的查找函数