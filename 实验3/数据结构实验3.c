#define _CRT_SECURE_NO_WARNINGS/*ONLY USING IN THE Visual Stdio 2019.OTHER COMPILERS CAN DELETE IT*/
#include<stdio.h>
#include<stdlib.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define INFEASIBLE -1
#define OVERFLOW -2
/*-----The above is universal, Do not delete-----*/
/*-----191491603 YuChen Cao-----*/
/*-----STACK-----DATA STRCTURE-----BASIC OPERATION-----*/
#define STACK_INIT_SIZE 10 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量
typedef int SElemType;
typedef int Status;
typedef struct/*Sequential storage of stack*/
{
	SElemType* base;/*The bottom pointer of the stack*/
	SElemType* top;/*The top pointer of the stack*/
	int stacksize;/*The allocated storage space*/
}SqStack;
Status InitStack(SqStack* S)/*Create an empty stack*/
{
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status GetTop(SqStack* S, SElemType* e)/*Check the stack is or not empty*/
{
	if (S->top == S->base) return ERROR;/*The bottom pointer is equal to the top pointer ==> there are no elements in the stack*/
	e = *(S->top - 1);/*The top pointer must on top of the top element */
	return OK;
}
Status Push(SqStack* S, SElemType e)/*Add a new element in the stack*/
{
	if (S->top - S->base >= S->stacksize)/*If the stack is filled*/
	{
		S->base = (SElemType*)realloc(S->base, S->stacksize + STACKINCREMENT * sizeof(SElemType));/*Increase storage space*/
		//<==
		S->stacksize += STACKINCREMENT;
	}
	*S->top = e;
	*S->top++;/*The book says " *S.top ++= e ",The two says are equivalent.*/
}
Status Pop(SqStack* S)
{
	SElemType e = 0;
	if (S->top == S->base) return ERROR;/*equal to line 33*/
	S->top = S->top - 1;
	e = *(S->top);/*this line and last says " e = * -- S.top",The two says are equivalent.*/
	return e;
}
void check(SqStack S)
{
	int i = 0;
	if (S.top == S.base)
	{
		printf("now it is an empty stack");
		return ERROR;
	}
	printf("Now check your stack:");
	S.top--;
	while (S.top != S.base)
	{
		printf("%d ", *(S.top));
		S.top--;
	}/*This loop can output all element except the bottom element*/
	printf("%d\n", *(S.top));/*Output the bottom element */
}
void conversion(SqStack* S)
{
	int n = 0;
	printf("enter a number to conversion:");
	scanf("%d", &n);
	while (n)
	{
		Push(S, n % 2);
		n = n / 2;
	}
}
int main()
{
	SqStack S;
	int i = 0;//loop
	int n = 0;//The number of elements
	int num = 0;//element of the stack
	SElemType e = 0;//the top element of stack
	InitStack(&S);
	printf("enter the number of stack:");
	scanf("%d", &n);
	printf("enter the elements of the stack:");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		Push(&S, num);	/*enter n numbers in the stack*/
	}
	check(S);//ouput the stack
	for (i = 0; i < n; i++)
		e=Pop(&S);
	check(S);
	conversion(&S);
	check(S);
}