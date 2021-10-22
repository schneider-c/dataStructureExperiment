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
	Student* elem;//�洢�ռ��ַ
	int length;//��ǰ����
	int listsize;//����Ĵ洢����
}SqList;//���Ա�ṹ��
int InitList_sq(SqList* L)
{
	L->elem = (Student*)malloc(LIST_INIT_SIZE * sizeof(Student));//���� ���� ��ElemType�Ŀռ�
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}//����ռ�
Student Input_data()
{
	Student data;
	printf("ѧ�ţ�");
	scanf("%d", &data.StudentNo);
	printf("������");
	scanf("%s", &data.Name);
	printf("���ĳɼ���");
	scanf("%d", &data.Chinese);
	printf("��ѧ�ɼ���");
	scanf("%d", &data.Math);
	printf("Ӣ��ɼ���");
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
}//���Ա�ֵ
void check(SqList L,int i)
{
	printf("ѧ�ţ�%d ", L.elem[i].StudentNo);
	printf("������%s ", L.elem[i].Name);
	printf("���ģ�%d ", L.elem[i].Chinese);
	printf("��ѧ��%d ", L.elem[i].Math);
	printf("Ӣ�%d ", L.elem[i].English);
	printf("�ܷ֣�%d ", L.elem[i].Score);
	printf("\n");
}
void QuickSort(SqList* L, int low, int high) {
	int i = low;
	int j = high;
	int key = L->elem[low].Score;
	Student temp;
	if (low >= high)  //���low >= high˵�����������
		return;
	while (low < high) {  //��whileѭ������һ�α�ʾ�Ƚ���һ��
		while (low < high && key <= L->elem[high].Score)
			--high;  //��ǰѰ��
		if (key > L->elem[high].Score) {
			temp = L->elem[low];
			L->elem[low] = L->elem[high];
			L->elem[high] = temp;
			++low;
		}
		while (low < high && key >= L->elem[low].Score)
			++low;  //���Ѱ��
		if (key < L->elem[low].Score) {
			temp = L->elem[low];
			L->elem[low] = L->elem[high];
			L->elem[high] = temp;
			--high;
		}
	}
	QuickSort(L, i, low - 1);  //��ͬ���ķ�ʽ�Էֳ�������ߵĲ��ֽ���ͬ�ϵ�����
	QuickSort(L, low + 1, j);  //��ͬ���ķ�ʽ�Էֳ������ұߵĲ��ֽ���ͬ�ϵ�����
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
	InitList_sq(&L);//�˴���������Ϊ10�����Ա�
	Input(&L);//���Ա�ֵ
	printf("����ǰ��\n");
	for(i=0;i<LIST_INIT_SIZE;i++) 
		check(L,i);//���Ա��������

	printf("\n�����\n");
	QuickSort(&L, 0, L.length - 1);
	for (i = 0; i < LIST_INIT_SIZE; i++)
		check(L, i);//���Ա��������

	printf("\n������ҹ���\n1.�����ķ�����ѯ\n2.����ѧ������ѯ\n3.��Ӣ�������ѯ\n��ѯ��");
	scanf("%d", &choose);
	printf("����Ҫ��ѯ�ķ�����");
	scanf("%d", &findScore);
	find(L, choose, findScore);
	return 0;
}
