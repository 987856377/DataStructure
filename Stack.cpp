#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<time.h>
#define N 10
using namespace std;

class Stack{
	private:
		int data;
	    Stack *next;
	public: 
	    void Init(Stack *&S);
	    bool Push(Stack *&S,int data);
	    bool Pop(Stack *&S,int &data);
	    bool IsEmpty(Stack *&S);
	    void Show(Stack *&S);
	    void Destroy(Stack *&S);
};

void Stack::Init(Stack *&S){
	S = new Stack;
	S->next = NULL;	
}

bool Stack::IsEmpty(Stack *&S){
	return S->next==NULL;
}

bool Stack::Push(Stack *&S,int data){
	Stack *ptr=S->next;
	ptr = new Stack;
	ptr->data=data;
	ptr->next=S->next;
	S->next=ptr;
} 

bool Stack::Pop(Stack *&S,int &data){
	Stack *ptr=S->next;
	if(IsEmpty(S)){
		return false;
	}
	data=ptr->data;
	S->next=ptr->next;
	free(ptr);
	return true;
}

void Stack::Show(Stack *&S){
	Stack *ptr=S->next;
	while(ptr){
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}
}

void Stack::Destroy(Stack *&S){
	Stack *ptr=S->next;
	while(ptr){
		free(S);
		S=ptr;
		ptr=ptr->next;
	}
	
}

int main(){
	
	Stack *S;
	srand(time(0));
	S->Init(S);
	
	cout<<"是否为空："<<S->IsEmpty(S)<<endl;
	
	for(int i=0;i<9;i++){
		S->Push(S,rand()%100);
	}
	cout<<"是否为空："<<S->IsEmpty(S)<<endl;
	cout<<"栈中数据：";
	S->Show(S); 
	
	cout<<endl;
	int data;
	S->Pop(S,data);
	cout<<"出栈："<<data<<"  ";
	cout<<endl<<"出栈后 ："; 
	S->Show(S);
	
	cout<<endl<<"是否为空："<<S->IsEmpty(S)<<endl;
	
	cout<<"销毁..."<<endl; 
	Sleep(500);
	S->Destroy(S);
	cout<<"是否为空："<<S->IsEmpty(S)<<endl;
	return 0;
}
