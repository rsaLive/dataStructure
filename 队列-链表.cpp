#include <stdio.h>;
#include <stdlib.h>;

//����ڵ��������
typedef struct Node
{
	int data;
	struct Node * PNext;
}* PNode,Node;

typedef struct Queue
{
	PNode fornt;//����ͷ
	PNode rear;//����β
}* PQueue,Queue;

//��������
void create_queue(PQueue);
//����м�����
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
		printf("ɾ����������%d\n",val);
	}else{
		printf("ɾ��ʧ��\n");
	}
 

	traverse(&qu);
}

void create_queue(PQueue pq)
{
	pq->fornt = (PNode)malloc(sizeof(Node));
	if(pq->fornt == NULL){
		printf("�ڴ����ʧ��");
		exit(-1);
	}
	pq->rear=pq->fornt;
	pq->fornt->PNext=NULL;
}



bool add(PQueue pq,int val)
{
	
	PNode PNew =(PNode)malloc(sizeof(Node));
	if(PNew == NULL){
		printf("�ڴ����ʧ��\n");
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
		printf("�ն���");
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
		printf("����Ϊ��\n");
		exit(-1);
	}
	PNode p=pq->fornt;
	while(p != pq->rear){
		printf("%d\n",p->data);
		p=p->PNext;
	}
}

