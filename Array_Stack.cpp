#include<iostream>
#include<cstdlib>
#define MaxSize 50
typedef int ElemType;
using namespace std;
typedef struct Stack{
	ElemType data[MaxSize];
	ElemType top;
}Stack;
void initStack(Stack *&S){
	S = new Stack;
	S->top=-1;
}
void destroy(Stack *&S){
	free(S);
}
int Stacklenth(Stack *&S){
	return S->top+1;
}
bool isEmpty(Stack *&S){
	return S->top==-1;
}
bool push(Stack *&S,int value){
	if(S->top==MaxSize-1){
		return false;
	}
	S->top++;
	S->data[S->top]=value;
	return true;
}
bool pop(Stack *&S){
	if(-1==S->top){
		return false;
	}
	S->top--;
	return true;
}
ElemType getTop(Stack *&S){
	if(-1==S->top){
	    return 0;
	}
	ElemType value;
	value=S->data[S->top];
	return value;
}
void show(Stack *&S){
	for(int i=S->top;i>=0;i--){
		cout<<S->data[i]<<"   "; 
	}
}
int main(){
	Stack *S;
	initStack(S);
	cout<<"初始化完成"<<endl;
	
	cout<<"入栈...";
	push(S,1);
	push(S,2);
	push(S,3);
	push(S,4);
	push(S,5);
	push(S,6);
	show(S);
	
	cout<<endl<<"判断是否为空："<<isEmpty(S)<<endl;
	
	cout<<"栈顶元素："<<getTop(S)<<endl;
	
	pop(S);
	
	cout<<"栈的长度为："<<Stacklenth(S)<<endl;
	cout<<"栈顶元素："<<getTop(S)<<endl; 
	show(S);
	
	return 0;
} 



