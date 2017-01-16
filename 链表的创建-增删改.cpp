#include <stdio.h>
#include <stdlib.h>

//����ڵ�
typedef struct Node
{
	int data;
	struct Node * PNext;
}*PNode,Node;

//��ʼ������
PNode create_list();//�����ڵ�
//��ӡ������
void traverse_list(PNode);
//ɾ���ڵ�pos  ��1 ��ʼ
void delete_node(PNode,int,int *);

//����ڵ�  pos ��1��ʼ
void insert_data(PNode,int ,int );
void main()
{
	//int val;
	//����ͷָ��
	PNode PHead=NULL;
	PHead=create_list();
	
	
	//delete_node(PHead,-1,&val);
	
	insert_data(PHead,-2,2);
	traverse_list(PHead);
}


PNode create_list()
{
	int len;
	int i;
	int val;
	//����ͷ�ڵ�
	PNode PHead=(PNode)malloc(sizeof(Node));
	//�ڴ治����������ַ����ڴ�ʧ�ܵ����  ��������᷵��NULL
	if(PHead == NULL){
		printf("�ڴ����ʧ��");
	}
	PNode Ptail=PHead;
	//��ͷ�ڵ��ָ����ָ��NULL  ���û���׽ڵ�ָ�������NULL 
	Ptail->PNext=NULL;

	/*
		˼·��
			����ڵ�ptail����Զָ��β�ڵ㣬һ��ʼֻ��ͷ��� ͷ���Ҳ��β�ڵ㣬����ָ��ͷ���
		
			���½���PNew�ڵ���ص�ptail�ڵ���棬���غ�֮��ptailָ���½���PNew�ڵ㣬������֤ptail��Զָ��β�ڵ�
	*/
	printf("�������ʼ���ڵ������\n");
	scanf("%d",&len);
	for(i=0;i<len;i++){
		printf("������ڵ��ֵ");
		scanf("%d",&val);

		PNode PNew=(PNode)malloc(sizeof(Node));
		PNew->data=val;
		Ptail->PNext=PNew;
		PNew->PNext=NULL;
		Ptail=PNew;
	}
	//�����׽ڵ�
	return PHead;
}

void traverse_list(PNode PHead)
{
	PNode p = PHead->PNext;
	//printf("%d\n",PHead->PNext);
	if(p == NULL)
	{
		printf("����Ϊ��\n");
		exit(0);
	}
	while(p != NULL){
		printf("%d\n",p->data);
		p=p->PNext;
	}

}

void delete_node(PNode PHead,int pos,int * val)
{
	
	int i=0;
	if(PHead->PNext==NULL){
		printf("�ڵ�Ϊ��");
		exit(0);
	}
	if(pos <0){
		printf("û������");
		exit(0);
	}
	PNode p=PHead;
	PNode t;
	PNode r;
	while(i != pos){
		//printf("%d\n",i=t->data);exit(0);
		t=p;
		if(i == pos-1){
			//printf("%d\n",i=p->PNext->PNext->data);exit(0);
			//exit(0);
			r=p->PNext;
			t->PNext=p->PNext->PNext;
			free(r);
			r=NULL;
			//exit(0);
			return;
		}
		i++;
		p=p->PNext;
	}
}

void insert_data(PNode PHead,int pos,int val)
{
	int i=0;
	PNode p=PHead;
	while(p != NULL && i<pos-1){
		p=p->PNext;
		i++;
	}
	if(p == NULL || i>pos -1){
		printf("�������");
		return ;
	}

	PNode PNew=(PNode)malloc(sizeof(Node));
	if(PNew == NULL){
		printf("�ڴ����ʧ��");
		exit(-1);
	}
	PNode t=p->PNext;
	PNew->data=val;
	PNew->PNext=t;
	p->PNext=PNew;
}