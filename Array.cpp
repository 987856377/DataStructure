#include<iostream>
#include<cstdlib>
#define MaxSize 50
typedef int ElemType;
using namespace std;
typedef struct SqList{
	ElemType data[MaxSize];
	int lenth;
}SqList; 
void InitList(SqList *&L){
	L = new SqList;
	L->lenth=0;	
}
void CreateList(SqList *&L,ElemType a[],int lenth){
	for(int i=0;i<lenth;i++){
		L->data[i]=a[i];
	}
	L->lenth=lenth;
}
void ShowList(SqList *&L){
	for(int i=0;i<L->lenth;i++){
		cout<<L->data[i]<<"  "; 
	}
	cout<<endl;
}
int ListLenth(SqList *&L){
    return L->lenth;
}
bool isEmpty(SqList *&L){
	return (L->lenth==0);
}
int getIndex(SqList *&L,int data){
	int i=0;
	while(i>=0&&L->data[i]!=data)
	    i++;
	if(i<=0) return 0;
	else return i+1; 
}
bool inseartList(SqList *&L,int location,ElemType value){
	int j=0;
	if(location<0||location>L->lenth-1)
	    return false;
	location--;	
	for(j=L->lenth;j>location;j--){
		L->data[j]=L->data[j-1];
	}
	L->lenth++;
	L->data[location]=value;	
	return true;
}
bool deleteList(SqList *&L,int location){
	int j=0;
	if(location<0||location>=L->lenth+1)
	    return false;
	location--;
	for(j=location;j<L->lenth;j++){
	    L->data[j]=L->data[j+1];
	}
	L->lenth--;
	return true;
}
void DestroyList(SqList *&L){
	free(L);
}
int main(){
	SqList *L;
	int a[6]={1,2,3,4,5,6};
	
	InitList(L);
	cout<<"初始化完成。"; 
	CreateList(L,a,6); 
	
	cout<<endl<<"输出创建的数组："; 
	ShowList(L);
	
	cout<<"数组的长度为："<<ListLenth(L)<<endl; 
	
	cout<<"查找元素的下标为："<<getIndex(L,3)<<endl;
	
	cout<<"判断是否为空："<<isEmpty(L)<<endl;
	
	cout<<"插入元素99："<<inseartList(L,5,99)<<"成功"<<endl;
	cout<<"输出数组："; 
	ShowList(L);
	
	cout<<"删除元素1："<<deleteList(L,1)<<"成功"<<endl;
	cout<<"输出数组："; 
	ShowList(L); 
	 
	DestroyList(L);
	cout<<"销毁线性表完成！！！"<<endl;
	return 0;
}

