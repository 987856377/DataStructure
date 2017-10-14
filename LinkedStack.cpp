#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct ListStack{
	ElemType data;
	struct ListStack *next;
}ListStack;

void initStack(ListStack *&head){
	head = new ListStack;
	head->next=NULL;
}
void push(ListStack *&head,int data){   //入栈 
	ListStack *ptr;
	ptr=new ListStack;
	ptr->data=data;
	ptr->next=head->next;         //入栈的数据为栈顶数据（头指针的下一个数据） 
	head->next=ptr;
}

bool pop(ListStack *&head){      //出栈 		
	ListStack *ptr=head->next;
	if(head->next==NULL)
	    return false;
	cout<<ptr->data<<endl;
	head->next=ptr->next;
	free(ptr);
	return true;
}
void show(ListStack *&head){
	ListStack *ptr=head->next;
	while(ptr!=NULL){
		cout<<ptr->data<<"   ";
		ptr=ptr->next;
	} 
}

int getLenth(ListStack *&head){
	ListStack *ptr=head->next;
	int i=0;
	while(ptr){
		i++;
		ptr=ptr->next;
	}
	return i;
} 

ElemType getTop(ListStack *&head){        //得到栈顶的元素 
	ListStack *ptr=head->next;
	return ptr->data;
}

bool isEmpty(ListStack *&head){      //判断是否为空 
	return head->next==NULL;
}

void destroy(ListStack *&head){
	ListStack *ptr=head->next;
	while(ptr){
		free(head);
		head=ptr;
		ptr=ptr->next;
	}
	free(head);
}
int main(){
	ListStack *head;
	initStack(head);
	cout<<"初始化完成..."<<endl;	
	cout<<"入栈..."<<endl;
	push(head,1);
	push(head,2);
	push(head,3);
	push(head,4);
	push(head,5);
	push(head,6);
	cout<<"入栈完成。"<<endl;
	cout<<"栈中数据为：";
	show(head);
	cout<<endl<<"栈的深度为："<<getLenth(head)<<endl;
	
	cout<<"栈顶元素："<<getTop(head)<<endl;
	
	cout<<endl<<"弹出栈顶元素"<<endl; 
	pop(head);
	cout<<"栈中数据为：";
	show(head);
	cout<<endl<<"栈的深度为："<<getLenth(head)<<endl;
	
	cout<<"栈顶元素："<<getTop(head)<<endl;
	
	cout<<"是否为空："<<isEmpty(head)<<endl; 
	
	destroy(head);
	cout<<endl<<"销毁完成"<<endl;
	cout<<"是否为空："<<isEmpty(head)<<endl; 
	return 0;
}
