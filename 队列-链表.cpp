#include <stdio.h>;
#include <stdlib.h>;

//定义节点变量类型
typedef struct Node
{
	int data;
	struct Node * PNext;
}* PNode,Node;

typedef struct Queue
{
	PNode fornt;//队列头
	PNode rear;//队列尾
}* PQueue,Queue;

//创建队列
void create_queue(PQueue);
//向队列加数据
bool add(PQueue,int);

bool isEmpty(PQueue);
bool del(PQueue,int *);

void traverse(PQueue);


void main()
{
	int val;
	Queue qu;
	create_queue(&qu);
	add(&qu,1);
	add(&qu,2);
	add(&qu,3);
	if(del(&qu,&val)){
		printf("删除的数据是%d\n",val);
	}else{
		printf("删除失败\n");
	}
 

	traverse(&qu);
}

void create_queue(PQueue pq)
{
	pq->fornt = (PNode)malloc(sizeof(Node));
	if(pq->fornt == NULL){
		printf("内存分配失败");
		exit(-1);
	}
	pq->rear=pq->fornt;
	pq->fornt->PNext=NULL;
}



bool add(PQueue pq,int val)
{
	
	PNode PNew =(PNode)malloc(sizeof(Node));
	if(PNew == NULL){
		printf("内存分配失败\n");
		exit(-1);
	}
	PNew->data=val;
	if(isEmpty(pq)){
		PNew->PNext=pq->rear;
		pq->fornt=PNew;
	}else{
		
		PNode p=pq->fornt;
		while(p->PNext != pq->rear){
			p=p->PNext;
		}
		//printf("%d\n",p->data);exit(-1);
		p->PNext=PNew;
		PNew->PNext=pq->rear;
	}

	return true;
}

bool isEmpty(PQueue pq)
{
	if(pq->fornt == pq->rear){
		return true;
	}
	return false;
}

bool del(PQueue pq,int * val)
{
	if(isEmpty(pq)){
		printf("空队列");
		exit(-1);
	}

	PNode p=pq->fornt;
	pq->fornt=p->PNext;
	
	*val= p->data;
	free(p);
	p=NULL;
	
	return true;
}

void traverse(PQueue pq)
{

	if(isEmpty(pq)){
		printf("队列为空\n");
		exit(-1);
	}
	PNode p=pq->fornt;
	while(p != pq->rear){
		printf("%d\n",p->data);
		p=p->PNext;
	}
}

