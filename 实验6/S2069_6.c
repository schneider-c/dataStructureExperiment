#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ture 1
typedef struct {
	int  book_No;
	char book_Name[80];
	char book_Author[20];
	int book_store;
	int book_Sum;
}Book;
typedef struct BiTNode{
	Book data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;
Book Insert_InputData()
{
	Book data;
	printf("书号：");
	scanf("%d",&data.book_No);
	//printf("书名：");
	//scanf("%s",&data.book_Name);
	//printf("作者：");
	//scanf("%s",&data.book_Author);
	//printf("购入数量：");
	//scanf("%d",&data.book_store);
	//data.book_Sum = data.book_store;
	return data;
}
BiTree InsertBST(BiTree T,Book data)
{
	if(T == NULL){
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = data;
		T->lchild = NULL;
		T->rchild = NULL;
	}else{
		if(data.book_No > T->data.book_No) T->rchild = InsertBST(T->rchild,data);
		else if(data.book_No < T->data.book_No) T->lchild = InsertBST(T->lchild,data);
		else T->data.book_Sum += data.book_Sum;
	}
	return T;
}
void root_first_check(BiTree T)
{
	if(T)
	{
		printf("%4d",T->data.book_No);//测试便利，仅输出书号
		root_first_check(T->lchild);
		root_first_check(T->rchild);
	}
}
int Delete(BiTree p)
{
	BiTree q,s;
	if(!p->rchild)
	{
		q=p;
		p=p->lchild;
		free(q);
	}else if(!p->lchild){
		q=p;
		p=p->rchild;
		free(q);
	}else{
		q=p;
		s=p->lchild;
		while(s->rchild){
			q=s;
			s=s->rchild;
		}
		p->data=s->data;
		if(q!=p) q->rchild=s->lchild;
		else q->lchild=s->lchild;
		free(s);
	}
	return ture;

}
int DeleteBST(BiTree T,int DeleteNo)
{
	BiTree *p;
	if(T)
	{
		if(DeleteNo==T->data.book_No) return Delete(T);
		else if(DeleteNo<T->data.book_No) return DeleteBST(T->lchild,DeleteNo);
		else return DeleteBST(T->rchild,DeleteNo);
	}
}
int main()
{
	BiTree T = NULL;
	int i=0;

	for(i=0;i<10;i++)
		T = InsertBST(T,Insert_InputData());
	root_first_check(T);

	printf("\n再输入一个节点\n");//插入
	T = InsertBST(T,Insert_InputData());
	root_first_check(T);
	printf("\n");

	DeleteBST(T,16);//删除
	root_first_check(T);
}