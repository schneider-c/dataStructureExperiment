#include<stdio.h>
#include<stdlib.h>
typedef int Status;
#define OK 1
#define ERROR -1
typedef struct Bitnode{
	char data;
	struct Bitnode *lchild,*rchild;
}Bitnode,*Bitree;
Bitree createTree(Bitree T){//1. 创建
	char ch;
	ch=getchar();
	if(ch=='#') T=NULL;
	else{
		T=(Bitree)malloc(sizeof(Bitnode));
		T->data=ch;
		T->lchild=createTree(T->lchild);
		T->rchild=createTree(T->rchild);
	}
	return T;
}
void check_root_first(Bitree T){//2.1 先序
	if(T){
		printf("%c",T->data);
		check_root_first(T->lchild);	
		check_root_first(T->rchild);
	}
}
void check_root_medium(Bitree T){//2.2 中序
	if(T){
		check_root_medium(T->lchild);
		printf("%c",T->data);	
		check_root_medium(T->rchild);
	}
}
void check_root_last(Bitree T){//2.3 后序
	if(T){
		check_root_last(T->lchild);
		check_root_last(T->rchild);
		printf("%c",T->data);
	}
}
int sumLeaf(Bitree T){//3. 叶子节点数
	if(T==NULL) return 0;
	else{
		if(T->lchild==NULL&&T->rchild==NULL) return 1;
		else return sumLeaf(T->lchild)+sumLeaf(T->rchild);
	}
}
int sum_1(Bitree T){//4.A 度数为1的节点数
		if(T==NULL) return 0;
	else{
		if(T->lchild!=NULL&&T->rchild==NULL||T->rchild!=NULL&&T->lchild==NULL) 
			return sum_1(T->lchild)+sum_1(T->rchild)+1;
		else return sum_1(T->lchild)+sum_1(T->rchild);
	}
}
int Bitree_deepth(Bitree T){//4.B 深度
	int leftDep=0;
	int rightDep=0;
	if(T){
		if(T->lchild==NULL) leftDep=0;
		else leftDep=Bitree_deepth(T->lchild);

		if(T->rchild==NULL) rightDep=0;
		else rightDep=Bitree_deepth(T->rchild);
	}
	return (rightDep>leftDep)? rightDep+1 : leftDep+1;
}
int mindeepth(Bitree T){//最小深度
	int leftdep;
	int rightdep;
	if(T==NULL) return 0;
	leftdep=mindeepth(T->lchild);
	rightdep=mindeepth(T->rchild);
	if(leftdep==0||rightdep==0) return leftdep+rightdep+1;
	else return ((leftdep < rightdep)? leftdep+1 : rightdep+1);

}
int main(){
	Bitree T;
	T=createTree(T);
	
	check_root_first(T);
	printf("\n");

	check_root_medium(T);
	printf("\n");

	check_root_last(T);
	printf("\n");

	printf("Number of leaf is %d\n",sumLeaf(T));
	printf("Number of point_1 is %d\n",sum_1(T));
	printf("deepth is %d\n",Bitree_deepth(T));
	printf("min deepth is %d\n",mindeepth(T));
}