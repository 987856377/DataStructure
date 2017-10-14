#include<iostream>
#include<cstdlib>
#include<time.h>
#include<windows.h>
#define N 10
using namespace std;

class LinkedList{
	private:
		int data;
		LinkedList *next;
	public:
	    LinkedList(){}
	    void Init(LinkedList *&L);
	    void Create(LinkedList *&L);
	    bool IsEmpty(LinkedList *&L);
	    bool Insert(LinkedList *&L,int key,int data);
	    bool Delete(LinkedList *&L,int data);
	    bool Reverse(LinkedList *&L);
	    void Destroy(LinkedList *&L);
	    void Show(LinkedList *&L);
		~LinkedList(){}
};

void LinkedList::Init(LinkedList *&L){
	L = new LinkedList;
	L->next = NULL;
}

void LinkedList::Create(LinkedList *&L){
	srand(time(0));
	LinkedList *ptr=L->next,*temp=L;
	for(int i=0;i<N;i++){
		ptr = new LinkList;
		ptr->data=rand()%100;
		temp->next = ptr;
		temp = ptr;
	}
	temp->next=NULL;
}

bool LinkedList::IsEmpty(LinkedList *&L){
	return (L->next==NULL);
}

bool LinkedList::Insert(LinkedList *&L,int key,int data){
	LinkedList *ptr=L->next,*temp;
	if(IsEmpty(L)){
		return false;
	}
	while(ptr){
		if(key==ptr->data){
			temp=new LinkList;
			temp->data=data;
			temp->next=ptr->next;
			ptr->next=temp;
			return true;
		}
		ptr=ptr->next;
	}
	return false;
}

bool LinkedList::Delete(LinkedList *&L,int data){
	LinkedList *ptr=L->next,*temp=L;
	if(IsEmpty(L)){
		return false;
	}
	while(ptr){
		if(data==ptr->data){
			temp->next=ptr->next;
			return true;
		}
		temp=ptr;
		ptr=ptr->next;
	}
}

bool LinkedList::Reverse(LinkedList *&L){
	LinkList *ptr=L->next,*temp=L;
	L->next=NULL;
	while(ptr){
		temp=ptr->next;
		ptr->next=L->next;
		L->next=ptr;
	    ptr=temp;
	} 
	return true;
}

void LinkedList::Show(LinkedList *&L){
	for(LinkedList *ptr=L->next;ptr;ptr=ptr->next){
		cout<<ptr->data<<"  ";
	}
	
}

void LinkedList::Destroy(LinkedList *&L){
	LinkedList *ptr=L->next;
	while(ptr){
		free(L);
		L=ptr;
		ptr=ptr->next;
	}
	free(L);
}
int main(){
	LinkedList *L;
	cout<<"初始化的链表为：";
	L->Init(L);
	L->Create(L);
	L->Show(L);
	
	cout<<endl<<"判断是否为空："<<L->IsEmpty(L)<<endl; 
	
	cout<<endl<<"插入后：";
	L->Insert(L,4,99);
	L->Show(L);
	
	
	cout<<endl<<"删除后：";
	L->Delete(L,8);
	L->Show(L);
	
	L->Reverse(L);
	cout<<endl<<"逆置：";
	L->Show(L);
	
	cout<<endl<<"销毁..."; 
	Sleep(500);
	L->Destroy(L);
	cout<<endl<<"判断是否为空："<<L->IsEmpty(L)<<endl; 
	return 0;
}
