#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct Node{
	ElemType data;
	struct Node *next;    //队列结构 
}Node;
typedef struct ListQueue{
	Node *front;
	Node *rear;           //队头和队尾指针 
}ListQueue;

void InitQueue(ListQueue *&head){
	head = new ListQueue;
	head->front=head->rear=NULL;//队头和队尾赋值为空 
}
void EnQueue(ListQueue *&head,int data){
	Node *ptr= new Node;
	ptr->data=data;
	ptr->next=NULL;
	if(head->front==NULL){
		head->front=head->rear=ptr;
	}
	else{
		head->rear->next=ptr;
		head->rear=ptr;
	}
}
bool DeQueue(ListQueue *&head,ElemType &data){
	Node *ptr;
	if(head->rear==NULL){
		return false;
	}
	ptr=head->front;
	data = ptr->data;
	if(head->front==head->rear){
		head->front=head->rear=NULL;
	}
	else{
		head->front=head->front->next;
	}
	free(ptr);
	return true;
}
bool isEmpty(ListQueue *&head){
	return head->front==head->rear;
}
int lenth(ListQueue *&head){
	Node *ptr=head->front;
	int i=0;
	if(ptr==NULL){
		return 0;
	}
	while(ptr){
		i++;
		ptr=ptr->next;
	}
	return i;
}

void showQueue(ListQueue *&head){
	
	Node *ptr = head->front;
	while(ptr){
		cout<<ptr->data<<"  ";
		ptr = ptr->next;
	}
}
void destroy(ListQueue *&head)  //销毁链队
{
    Node *ptr=head->front->next;   //p指向队头数据节点
    while(ptr){
    	free(head->front);
    	head->front=ptr;
    	ptr=ptr->next;
	}
	free(head->front);
}
int main(){
	ListQueue *head;
	
	InitQueue(head);
	cout<<"初始化队列完成..."<<endl;
	
	for(int i = 0;i<9;i++){
		EnQueue(head,i);
	}
	cout<<"入队完成..."<<endl;
	cout<<"队列中的元素为：";
	showQueue(head);
	cout<<"\n队列的长度："<<lenth(head)<<endl;
	cout<<"是否为空："<<isEmpty(head)<<endl;
	
	for(int i = 0;i<4;i++){
		ElemType data;
		DeQueue(head,data);
		cout<<"已出队一个元素:"<<data<<endl;
	}
	
	cout<<"队列的长度："<<lenth(head)<<endl;
	
	cout<<"队列中的元素为：";
	showQueue(head);
	cout<<"\n队列的长度："<<lenth(head)<<endl;
	
	destroy(head);
	cout<<"\n已销毁队列."<<endl;
	cout<<"是否为空："<<isEmpty(head)<<endl;
	
	return 0;
}
