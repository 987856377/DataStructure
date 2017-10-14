#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct DoubleList{
	int data;
	struct DoubleList *pre;
	struct DoubleList *next;
}DoubleList;

void initList(DoubleList *&head){
	head = new DoubleList;
	head->pre=head->next=NULL;
	
}
DoubleList *createList(DoubleList *&head){
	DoubleList *ptr=head->next,*temp=head;
	int n;
    cout<<"请输入要创建多少数据：";
    cin>>n;
    for(int i=0;i<n;i++){
    	ptr = new DoubleList;
    	cin>>ptr->data;
    	temp->next=ptr;
    	ptr->pre=temp;
    	temp=ptr;
	}
	temp->next=NULL;
	return head;
}
bool inseartList(DoubleList *&head,int key,int value){
	DoubleList *ptr=head->next,*Node;
	while(ptr){
		if(key==ptr->data){
			Node = new DoubleList;
			Node->data=value;
			Node->next=ptr->next;
			Node->pre=ptr;
			ptr->next=Node;
			cout<<"插入完成"<<endl;
			return true; 
		}
		ptr=ptr->next;
	}
	cout<<"插入失败,可能没找到您要插入的位置..."<<endl;
	return false;
}
bool deleteList(DoubleList *&head,int data){
	DoubleList *temp = head,*ptr=head->next;
	while(ptr){
		if(data==ptr->data){
			temp->next=ptr->next;
			cout<<"删除成功"<<endl;
			free(ptr);
			return true;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	cout<<"删除失败,可能链表中没有这个数..."<<endl;
	return false;
}
void showList(DoubleList *&head){
	DoubleList *ptr=head->next;
	while(ptr){
		cout<<ptr->data<<"   ";
		ptr=ptr->next; 
	}
}
int main(){
	DoubleList *head;
	
	initList(head);
	cout<<"初始化完成"<<endl;
	
	head=createList(head);
	cout<<"创建完成"<<endl;
	
	cout<<"输出链表：";
	showList(head); 
	
	cout<<"插入数据...";
	inseartList(head,2,9);
	cout<<"输出链表：";
	showList(head);
	
	cout<<endl<<"删除数据...";
	deleteList(head,2);
	cout<<"输出链表：";
	showList(head);
	 
	return 0;
}
