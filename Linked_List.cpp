#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct LinkedList{
	ElemType data;
	struct LinkedList *next;
}LinkedList;
void initList(LinkedList *&head){   //初始化链表 
	head = new LinkedList;
	head->next=NULL;
}

LinkedList *createList(LinkedList *&head){	  //尾插法 
	LinkedList *temp=head,*ptr=head->next;
	int n;
	cout<<"请输入要创建多少元素：";
	cin>>n;
	for(int i=0;i<n;i++){
		ptr=new LinkedList;
		cin>>ptr->data;
		temp->next=ptr;
		temp=ptr;
	}
	temp->next=NULL;
	return head;
}
void appendList(LinkedList *&head,int data){     //在尾部追加 
	LinkedList *ptr=head->next,*temp;
	temp = new LinkedList;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->data=data;
	temp->next=NULL;
}
void showList(LinkedList *&head){     //输出链表 
	LinkedList *ptr=head->next;
	while(ptr){
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}
	cout<<endl;
}
bool isEmpty(LinkedList *&head){      //判断是否为空 
	return (head->next==NULL);
}
bool inseartList(LinkedList *&head,int data){     //在链表中插入数据 
	LinkedList *ptr=head->next,*Node;
	int n;
	cout<<endl<<"请输入要在那位数后面插入：";
	cin>>n; 
	while(ptr){
		if(n==ptr->data){
			Node=new LinkedList;
			Node->data=data;
			Node->next=ptr->next;
			ptr->next=Node;
			cout<<"插入数据完成"<<endl;
			return true;
		}		
		ptr=ptr->next;
	}
	cout<<"查无此数"<<endl;
	return false;	 
} 
bool deleteList(LinkedList *&head,int data){    //删除链表中的数据 
	LinkedList *ptr=head->next,*temp=head;
	while(ptr){
		if(data=ptr->data){
			temp->next=ptr->next;
			cout<<"删除成功"<<endl;
			free(ptr);
			return true;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	cout<<"查无此数"<<endl;
	return false;
} 
bool updateList(LinkedList *&head,int key,int value){    //更改链表中的数据 
	LinkedList *temp=head,*ptr=head->next;
	while(ptr){
		if(key==ptr->data){
			ptr->data=value;
			cout<<"修改完成"<<endl;
			return true;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	cout<<"修改失败,链表中可能没有您想修改的数..."<<endl;
	return false; 
}
int getLocation(LinkedList *&head,int data){     //得到数据在链表中的位置 
	LinkedList *ptr=head->next,*temp=head;
	int i=0;
	while(ptr){
		i++;
		if(data==ptr->data){
			return i;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	cout<<"查无此数"<<endl;
	return 0;
}

void reverseList(LinkedList *&head){
	LinkedList *ptr=head->next,*temp=head;
	head->next=NULL;
	while(ptr!=NULL){
		temp=ptr->next;
		ptr->next=head->next;
		head->next=ptr;
		ptr=temp;
	} 
}
void destroyList(LinkedList *&head){   //销毁链表 
	LinkedList *ptr=head->next;
	while(ptr){
		free(head);
		head=ptr;
		ptr=ptr->next;
	}
	free(head);
} 
int main(){
	LinkedList *head;
	initList(head);
	cout<<"初始化完成！"<<endl;
	head=createList(head);
	cout<<"创建链表完成"<<endl;
	
	cout<<endl<<"是否为空："<<isEmpty(head)<<endl;
	
	cout<<endl<<"输出链表：";
	showList(head);
	
	cout<<endl<<"将要在链表中插入数据..."<<endl; 
	inseartList(head,7);	 
	cout<<"输出链表：";
	showList(head);
	cout<<endl<<"是否为空："<<isEmpty(head)<<endl;
	
	cout<<endl<<"要查找的数在链表中的位置为："<<getLocation(head,5)<<endl;
	
	cout<<endl<<"将要删除链表中的数据..."<<endl; 
	deleteList(head,1);
	cout<<"输出链表：";
	showList(head);
	
	cout<<endl<<"要查找的数在链表中的位置为："<<getLocation(head,2)<<endl; 
	
	
	cout<<"修改数据...";
	updateList(head,2,99);
	cout<<"输出链表：";
	showList(head);
	
	cout<<endl<<"追加数据...";
	appendList(head,78);
	cout<<"输出链表：";
	showList(head);
	
	cout<<endl<<"链表逆置：";
	reverseList(head);
	showList(head);
	 
	destroyList(head);	
	cout<<endl<<"销毁链表完成"<<endl;
	cout<<endl<<"是否为空："<<isEmpty(head)<<endl;
	
	return 0;
}

/*
void Link(LinkList *&L1, LinkList *&L2)
{
    LinkList *p= L1;
    while(p->next != NULL)   //找到L1的尾节点
        p = p->next;
    p->next = L2->next;  //将L2的首个数据节点连接到L1的尾节点后
    free(L2);   //释放掉已经无用的L2的头节点
}
*/

