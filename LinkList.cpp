#include<iostream>
#include<cstdlib>
#include<time.h>
#include<windows.h>
#define N 10
using namespace std;

class LinkList{
	private:
		int data;
		LinkList *next;
	public:
	    LinkList(){}
	    void Init(LinkList *&L);
	    void Create(LinkList *&L);
	    bool IsEmpty(LinkList *&L);
	    bool Insert(LinkList *&L,int key,int data);
	    bool Delete(LinkList *&L,int data);
	    bool Reverse(LinkList *&L);
	    void Destroy(LinkList *&L);
		void Show(LinkList *&L);
		~LinkList(){}
};

void LinkList::Init(LinkList *&L){
	L = new LinkList;
	L->next = NULL;
}

void LinkList::Create(LinkList *&L){
	srand(time(0));
	LinkList *ptr=L->next,*temp=L;
	for(int i=0;i<N;i++){
		ptr = new LinkList;
		ptr->data=rand()%100;
		temp->next = ptr;
		temp = ptr;
	}
	temp->next=NULL;
}

bool LinkList::IsEmpty(LinkList *&L){
	return (L->next==NULL);
}

bool LinkList::Insert(LinkList *&L,int key,int data){
	LinkList *ptr=L->next,*temp;
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

bool LinkList::Delete(LinkList *&L,int data){
	LinkList *ptr=L->next,*temp=L;
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

bool LinkList::Reverse(LinkList *&L){
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

void LinkList::Show(LinkList *&L){
	for(LinkList *ptr=L->next;ptr;ptr=ptr->next){
		cout<<ptr->data<<"  ";
	}
	
}

void LinkList::Destroy(LinkList *&L){
	LinkList *ptr=L->next;
	while(ptr){
		free(L);
		L=ptr;
		ptr=ptr->next;
	}
	free(L);
}
int main(){
	LinkList *L;
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
