#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define MAX_VERTEX_NUM 20 //�������
typedef enum { DG, DNUDG, UDN } GraphKind;//ͼ������

/*��ͷ���ӵı��н�㶨��*/
typedef struct ArcNode {
	int adjvex;//�ߵ��յ�λ��
	struct ArcNode* nextArc;
}ArcNode;//���߱�Ľ��ṹ����

/*��ͷ�ڵ㶨��*/
typedef struct VNode {
	int data;//����
	ArcNode* firstarc;//ָ���ڽӵ��ָ��
}VNode, Adjlist[MAX_VERTEX_NUM];//�洢��ͷ��������

/*ͼ���ڽӱ���*/
typedef struct {
	Adjlist vertices;
	int vexnum, arcnum;//��¼�������ͱ���
	GraphKind Kind;//ͼ������
}Algraph;

void createGraph(Algraph* G)
{
	int i = 0, j = 0, k = 0;
	ArcNode* s;
	G->Kind = DG;//�涨ͼ������

	printf("���붥�����ͱ���\n");
	scanf("%d%d", &G->vexnum, &G->arcnum);

	printf("���붥����Ϣ�������������0��ʼ\n");
	for (i = 0; i < G->vexnum; i++)//����������
	{
		scanf("%d", &G->vertices[i].data);
		G->vertices[i].data = i;
		G->vertices[i].firstarc = NULL;
	}

	printf("����%d��������ʽ����������ϢA,������ϢB��\n", G->arcnum);
	for (k = 0; k < G->arcnum; k++)
	{
		scanf("%d,%d", &i, &j);
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->nextArc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = s;
	}
}

int visit[MAX_VERTEX_NUM] = { 0 };//ȫ�ֱ������鿴����Ƿ񱻷���

/* v�ǿ�ʼDFS�Ľ�� */
void DFS(Algraph G, int v)
{
	ArcNode* w;
	visit[v] = 1;
	printf("%3d", G.vertices[v].data);

	for (w = G.vertices[v].firstarc; w; w = w->nextArc)
		if (!visit[w->adjvex])
			DFS(G, w->adjvex);
}
void DFSGraph(Algraph G)
{
	int i = 0;
	for (i = 0; i < G.vexnum; i++)
	{
		if (!visit[i])
		{
			printf("��%d�㿪ʼ��DFS�����", i);
			DFS(G, i);
			putchar('\n');
		}
	}
}
int OutputDegree(Algraph G, int i)
{
	ArcNode* p;
	p = G.vertices[i].firstarc;
	int count = 0;
	while (p)
	{
		p = p->nextArc;
		count++;
	}
	return count;
}
int OutputEntry(Algraph G, int i)
{
	int j = 0;
	int count = 0;
	for (j = 0; j < G.vexnum; j++)
	{
		ArcNode* p;
		p = G.vertices[j].firstarc;
		while (p)
		{
			if (p->adjvex == i)
				count++;
			p = p->nextArc;
		}
	}
	return count;
}

int main()
{
	int countDegree = 0;
	int countIndegree = 0;
	Algraph G;
	createGraph(&G);

	DFSGraph(G);

	printf("����Ҫ�����ȵĵ㣺");
	scanf("%d", &countDegree);
	printf("%d�ŵ�ĳ�����%d\n", countDegree, OutputDegree(G, countDegree));

	printf("����Ҫ������ȵĵ㣺");
	scanf("%d", &countIndegree);
	printf("%d��������%d\n", countIndegree, OutputEntry(G, countIndegree));
}
/* ��������1: 8 10 0,1 1,2 1,3 2,4 3,4 0,5 5,6 5,7 6,7 5,3 */
/* ��������2��6 10 1,2 1,3 1,4 2,3 3,0 4,0 4,3 5,4 0,1 0,5 */

