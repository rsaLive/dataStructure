#include <stdio.h>
#include <stdlib.h>

/*
	栈是特殊的链表
	栈有栈顶和栈底
*/

//定义一个节点变量类型
typedef struct  Node
{
	int data;
	struct Node * PNext;
}*PNode,Node;

//定义栈底和栈顶变量类型
typedef struct Stack
{
	PNode  Ptop;
	PNode  Pbottom;
}Stack,* PStack;

bool init(PStack);//初始化栈
bool push(PStack,int);//压栈
void pop(PStack,int *);//出栈  返回出栈的值
void traverse(PStack);//遍历栈  
bool isEmpty(PStack);//判断是否为空
void clear(PStack);
void main()
{
	//定义栈的变量
	Stack s;
	int val;
	
	if(init(&s)){
		printf("初始化栈成功\n");
	}else{
		printf("初始化栈失败\n");
	}

	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);
	//pop(&s,&val);
	//printf("弹出的元素是%d\n",val);

	clear(&s);
	traverse(&s);

}

bool init(PStack ps)
{
	//定义头结点
	ps->Ptop=(PNode)malloc(sizeof(Node));
	if(ps->Ptop == NULL){
		printf("内存分配失败");
		return false;
	}
	ps->Ptop->PNext=NULL;
	ps->Pbottom=ps->Ptop;
	
	return true;
	
}

bool push(PStack ps,int val)
{
	
	PNode PNew=(PNode)malloc(sizeof(Node));
	if(PNew == NULL){
		printf("内存分配失败");
		return false;
	}
	PNew->data=val;
	PNew->PNext=ps->Ptop;
	ps->Ptop=PNew;
	
	return true;

}

void traverse(PStack ps)
{
	if(isEmpty(ps)){
		printf("空栈\n");
		exit(-1);
	}
	PNode p=ps->Ptop;
	while(p != ps->Pbottom){
		printf("%d\n",p->data);
		p=p->PNext;
	}
}

bool isEmpty(PStack ps)
{
	if(ps->Ptop == ps->Pbottom){
		return true;
	}
	return false;
}

void pop(PStack ps ,int * val)
{
	if(isEmpty(ps)){
		printf("空栈\n");
		exit(-1);
	}
	
	PNode p =ps->Ptop;
	ps->Ptop=p->PNext;
	* val =p->data;
	free(p);
	p=NULL;
	
}
void clear(PStack ps)
{
	if(isEmpty(ps)){
		printf("空栈\n");
		exit(-1);
	}
	PNode p =ps->Ptop;
	PNode r;
	while(p != ps->Pbottom){\

		
		//free(r);
		r=p->PNext;
		free(p);
		p=r;
	}
	ps->Ptop=ps->Pbottom;
}
