#include <stdio.h>
#include <stdlib.h>

/*
	ջ�����������
	ջ��ջ����ջ��
*/

//����һ���ڵ��������
typedef struct  Node
{
	int data;
	struct Node * PNext;
}*PNode,Node;

//����ջ�׺�ջ����������
typedef struct Stack
{
	PNode  Ptop;
	PNode  Pbottom;
}Stack,* PStack;

bool init(PStack);//��ʼ��ջ
bool push(PStack,int);//ѹջ
void pop(PStack,int *);//��ջ  ���س�ջ��ֵ
void traverse(PStack);//����ջ  
bool isEmpty(PStack);//�ж��Ƿ�Ϊ��
void clear(PStack);
void main()
{
	//����ջ�ı���
	Stack s;
	int val;
	
	if(init(&s)){
		printf("��ʼ��ջ�ɹ�\n");
	}else{
		printf("��ʼ��ջʧ��\n");
	}

	push(&s,2);
	push(&s,3);
	push(&s,4);
	push(&s,5);
	//pop(&s,&val);
	//printf("������Ԫ����%d\n",val);

	clear(&s);
	traverse(&s);

}

bool init(PStack ps)
{
	//����ͷ���
	ps->Ptop=(PNode)malloc(sizeof(Node));
	if(ps->Ptop == NULL){
		printf("�ڴ����ʧ��");
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
		printf("�ڴ����ʧ��");
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
		printf("��ջ\n");
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
		printf("��ջ\n");
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
		printf("��ջ\n");
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
