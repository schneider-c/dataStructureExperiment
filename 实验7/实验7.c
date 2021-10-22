#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 5
#define LISTINCREMENT 10
#define OK 1
typedef struct {
	int StudentNo;
	char Name[30];
	int Chinese;
	int Math;
	int English;
	int Score;
}Student;
typedef struct
{
	Student* elem;//存储空间基址
	int length;//当前长度
	int listsize;//分配的存储容量
}SqList;//线性表结构体
int InitList_sq(SqList* L)
{
	L->elem = (Student*)malloc(LIST_INIT_SIZE * sizeof(Student));//分配 定长 个ElemType的空间
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}//分配空间
Student Input_data()
{
	Student data;
	printf("学号：");
	scanf("%d", &data.StudentNo);
	printf("姓名：");
	scanf("%s", &data.Name);
	printf("语文成绩：");
	scanf("%d", &data.Chinese);
	printf("数学成绩：");
	scanf("%d", &data.Math);
	printf("英语成绩：");
	scanf("%d", &data.English);
	data.Score = data.Chinese + data.Math + data.English;
	printf("\n");
	return data;
}
void Input(SqList* L)
{
	int i = 0;
	printf("Input %d sets of data\n", LIST_INIT_SIZE);
	for (i = 0; i < LIST_INIT_SIZE; i++)
		L->elem[i] = Input_data();
	L->length = LIST_INIT_SIZE;
}//线性表赋值
void check(SqList L,int i)
{
	printf("学号：%d ", L.elem[i].StudentNo);
	printf("姓名：%s ", L.elem[i].Name);
	printf("语文：%d ", L.elem[i].Chinese);
	printf("数学：%d ", L.elem[i].Math);
	printf("英语：%d ", L.elem[i].English);
	printf("总分：%d ", L.elem[i].Score);
	printf("\n");
}
void QuickSort(SqList* L, int low, int high) {
	int i = low;
	int j = high;
	int key = L->elem[low].Score;
	Student temp;
	if (low >= high)  //如果low >= high说明排序结束了
		return;
	while (low < high) {  //该while循环结束一次表示比较了一轮
		while (low < high && key <= L->elem[high].Score)
			--high;  //向前寻找
		if (key > L->elem[high].Score) {
			temp = L->elem[low];
			L->elem[low] = L->elem[high];
			L->elem[high] = temp;
			++low;
		}
		while (low < high && key >= L->elem[low].Score)
			++low;  //向后寻找
		if (key < L->elem[low].Score) {
			temp = L->elem[low];
			L->elem[low] = L->elem[high];
			L->elem[high] = temp;
			--high;
		}
	}
	QuickSort(L, i, low - 1);  //用同样的方式对分出来的左边的部分进行同上的做法
	QuickSort(L, low + 1, j);  //用同样的方式对分出来的右边的部分进行同上的做法
}
void find(SqList L, int i,int findScore)
{
	int loop = 0;
	if (i == 1) {
		for (loop = 0; loop < LIST_INIT_SIZE; loop++) {
			if (L.elem[loop].Chinese == findScore) {
				check(L, loop);
				return OK;
			}
		}
	}
	else if (i == 2) {
		for (loop = 0; loop < LIST_INIT_SIZE; loop++) {
			if (L.elem[loop].Math == findScore) {
				check(L, loop);
				return OK;
			}
		}
	}
	else if (i == 3) {
		for (loop = 0; loop < LIST_INIT_SIZE; loop++) {
			if (L.elem[loop].English == findScore) {
				check(L, loop);
				return OK;
			}
		}
	}
}
int main()
{
	SqList L;
	int i = 0;
	int choose = 0, findScore = 0;
	InitList_sq(&L);//此处创建长度为10的线性表
	Input(&L);//线性表赋值
	printf("排序前：\n");
	for(i=0;i<LIST_INIT_SIZE;i++) 
		check(L,i);//线性表依次输出

	printf("\n排序后：\n");
	QuickSort(&L, 0, L.length - 1);
	for (i = 0; i < LIST_INIT_SIZE; i++)
		check(L, i);//线性表依次输出

	printf("\n输入查找规则：\n1.按语文分数查询\n2.按数学分数查询\n3.按英语分数查询\n查询：");
	scanf("%d", &choose);
	printf("输入要查询的分数：");
	scanf("%d", &findScore);
	find(L, choose, findScore);
	return 0;
}
