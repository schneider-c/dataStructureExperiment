#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define MAX_VERTEX_NUM 20 //顶点个数
typedef enum { DG, DNUDG, UDN } GraphKind;//图的种类

/*表头连接的表中结点定义*/
typedef struct ArcNode {
	int adjvex;//边的终点位置
	struct ArcNode* nextArc;
}ArcNode;//出边表的结点结构类型

/*表头节点定义*/
typedef struct VNode {
	int data;//数据
	ArcNode* firstarc;//指向邻接点的指针
}VNode, Adjlist[MAX_VERTEX_NUM];//存储表头结点的数组

/*图的邻接表定义*/
typedef struct {
	Adjlist vertices;
	int vexnum, arcnum;//记录顶点数和边数
	GraphKind Kind;//图的种类
}Algraph;

void createGraph(Algraph* G)
{
	int i = 0, j = 0, k = 0;
	ArcNode* s;
	G->Kind = DG;//规定图的种类

	printf("输入顶点数和边数\n");
	scanf("%d%d", &G->vexnum, &G->arcnum);

	printf("输入顶点信息，编号连续，从0开始\n");
	for (i = 0; i < G->vexnum; i++)//输入结点数据
	{
		scanf("%d", &G->vertices[i].data);
		G->vertices[i].data = i;
		G->vertices[i].firstarc = NULL;
	}

	printf("输入%d条弧，格式：“顶点信息A,顶点信息B”\n", G->arcnum);
	for (k = 0; k < G->arcnum; k++)
	{
		scanf("%d,%d", &i, &j);
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex = j;
		s->nextArc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = s;
	}
}

int visit[MAX_VERTEX_NUM] = { 0 };//全局变量，查看结点是否被访问

/* v是开始DFS的结点 */
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
			printf("从%d点开始，DFS结果：", i);
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

	printf("输入要检查出度的点：");
	scanf("%d", &countDegree);
	printf("%d号点的出度是%d\n", countDegree, OutputDegree(G, countDegree));

	printf("输入要检查出入度的点：");
	scanf("%d", &countIndegree);
	printf("%d点的入度是%d\n", countIndegree, OutputEntry(G, countIndegree));
}
/* 测试数据1: 8 10 0,1 1,2 1,3 2,4 3,4 0,5 5,6 5,7 6,7 5,3 */
/* 测试数据2：6 10 1,2 1,3 1,4 2,3 3,0 4,0 4,3 5,4 0,1 0,5 */

