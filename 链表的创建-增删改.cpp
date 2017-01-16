#include <stdio.h>
#include <stdlib.h>

//定义节点
typedef struct Node
{
	int data;
	struct Node * PNext;
}*PNode,Node;

//初始化函数
PNode create_list();//创建节点
//打印出链表
void traverse_list(PNode);
//删除节点pos  从1 开始
void delete_node(PNode,int,int *);

//插入节点  pos 从1开始
void insert_data(PNode,int ,int );
void main()
{
	//int val;
	//定义头指针
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
	//定义头节点
	PNode PHead=(PNode)malloc(sizeof(Node));
	//内存不足等情况会出现分配内存失败的情况  发生错误会返回NULL
	if(PHead == NULL){
		printf("内存分配失败");
	}
	PNode Ptail=PHead;
	//将头节点的指针域指向NULL  如果没有首节点指针域就是NULL 
	Ptail->PNext=NULL;

	/*
		思路：
			定义节点ptail，永远指向尾节点，一开始只有头结点 头结点也是尾节点，所以指向头结点
		
			将新建的PNew节点挂载到ptail节点后面，挂载好之后，ptail指向新建的PNew节点，这样保证ptail永远指向尾节点
	*/
	printf("请输入初始化节点的数量\n");
	scanf("%d",&len);
	for(i=0;i<len;i++){
		printf("请输入节点的值");
		scanf("%d",&val);

		PNode PNew=(PNode)malloc(sizeof(Node));
		PNew->data=val;
		Ptail->PNext=PNew;
		PNew->PNext=NULL;
		Ptail=PNew;
	}
	//返回首节点
	return PHead;
}

void traverse_list(PNode PHead)
{
	PNode p = PHead->PNext;
	//printf("%d\n",PHead->PNext);
	if(p == NULL)
	{
		printf("链表为空\n");
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
		printf("节点为空");
		exit(0);
	}
	if(pos <0){
		printf("没有数据");
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
		printf("插入错误");
		return ;
	}

	PNode PNew=(PNode)malloc(sizeof(Node));
	if(PNew == NULL){
		printf("内存分配失败");
		exit(-1);
	}
	PNode t=p->PNext;
	PNew->data=val;
	PNew->PNext=t;
	p->PNext=PNew;
}