#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct LNode {
	char word[20];
	struct LNode* next;
}LNode, * LinkList;
LinkList createList_L(LinkList L)
{
	char temp[10];
	printf("输入空格以分隔单词，句子末尾输入' #'以结束输入\n");
	scanf("%s", &temp);
	while (temp[0] != '#')
	{
		LinkList newpoint = (LinkList)malloc(sizeof(LNode));
		strcpy(newpoint->word, temp);
		newpoint->next = L->next;
		L->next = newpoint;
		scanf("%s", &temp);
	}

	LinkList q1 = NULL;
	LinkList q2 = NULL;
	q1 = L->next;
	L->next = NULL;
	while (q1)
	{
		q2 = q1;
		q1 = q1->next;
		q2->next = L->next;
		L->next = q2;
	}
}
void check(LinkList L)
{
	LinkList point = NULL;
	point = L->next;
	while (point)
	{
		printf("%s ", point->word);
		point = point->next;
	}
	printf("\n");
}
void Sort(LinkList L)
{
	LinkList p = NULL;
	LinkList q = NULL;
	char temp[10];
	for (p = L->next; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (strcmp(p->word, q->word) > 0)
			{
				strcpy(temp, p->word);
				strcpy(p->word, q->word);
				strcpy(q->word, temp);
			}
		}
	}

}
void link(LinkList L1, LinkList L2)//将L2合并到L1上
{
	LinkList pointL1 = L1->next;

	while (pointL1)
	{
		LinkList pointL2 = L2->next;
		LinkList lastL2 = L2;
		while (pointL2)
		{
			if (strcmp(pointL1->word, pointL2->word) == 0)
			{
				lastL2->next = lastL2->next->next;
			}
			pointL2 = pointL2->next;
			lastL2 = lastL2->next;
		}
		pointL1 = pointL1->next;
	}

	pointL1 = L1->next;
	while (pointL1) {
		if (pointL1->next == NULL) {
			pointL1->next = L2->next;
			break;
		}
		pointL1 = pointL1->next;
	}
}
/*测试数据：
give people wonderful tools #
and they will do wonderful things #
*/
int main()
{
	LinkList L1 = (LinkList)malloc(sizeof(LNode));
	L1->next = NULL;
	printf("Enter a piece of text in L1\n");
	createList_L(L1);


	LinkList L2 = (LinkList)malloc(sizeof(LNode));
	L2->next = NULL;
	printf("Enter a piece of text in L2\n");
	createList_L(L2);

	printf("L1:");//输出正常顺序的L1
	check(L1);
	printf("\nL2:");//输出正常顺序的L2
	check(L2);

	printf("\n\nL1 when sorted:");//输出排序后的L1
	Sort(L1);
	check(L1);

	printf("\nL2 when sorted:");//输出排序后的L2
	Sort(L2);
	check(L2);

	link(L1, L2);//连接L1，L2并删除重复词
	printf("\n\nL1:");
	check(L1);//输出连接后的L1
}