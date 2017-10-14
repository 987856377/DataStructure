#include<iostream>
#include<cstdlib> 
#include<time.h>
#define SIZE 9
using namespace std;
class ArrayList{
	private:
		//ArrayList *L;
		int data[SIZE];
		int lenth;
	public:
		void Init(ArrayList *&L);
		void Create(ArrayList *&L);
		bool Insert(ArrayList *&L,int index,int value);
		bool Delete(ArrayList *&L,int index);
		bool IsEmpty(ArrayList *&L);
		void Destroy(ArrayList *&L);
		void Show(ArrayList *&L);
		~ArrayList(){
		}
};

void ArrayList::Init(ArrayList *&L){
	L = new ArrayList;
	L->lenth=-1;
}

void ArrayList::Create(ArrayList *&L){
	srand(time(0));
	for(int i=0;i<SIZE;i++){
		L->data[i]  = rand()%100;
		L->lenth++;
	}
}

void ArrayList::Show(ArrayList *&L){
	for(int i=0;i<L->lenth;i++){
		cout<<L->data[i]<<"  ";
	}
}

bool ArrayList::IsEmpty(ArrayList *&L){
	return L->lenth==-1;
}

bool ArrayList::Insert(ArrayList *&L,int index,int value){
	if(IsEmpty(L)){
		cout<<"数组为空。"<<endl;
		return false;
	}
	else{
		index--;
		for(int i=L->lenth;i>index;i--){
			L->data[i] = L->data[i-1];
		}
		L->lenth++;
		L->data[index] = value;
		return true;
	}
}

bool ArrayList::Delete(ArrayList *&L,int index){
    if(IsEmpty(L)){
    	cout<<"数组为空。"<<endl;
    	return false;
	}
	else{
		index--;
		for(int i=index;i<L->lenth;i++){
			L->data[i] = L->data[i+1];
		}
		L->lenth--;
		return true;
	}	
}

void ArrayList::Destroy(ArrayList *&L){
	L->lenth=-1;
}
int main(){
	ArrayList *L;
	L->Init(L);
	cout<<"初始化的数组为：";
	L->Create(L);	
	L->Show(L);
	
	cout<<endl<<"插入后：";
	L->Insert(L,2,100);
	L->Show(L);
	
	cout<<endl<<"删除后：";
	L->Delete(L,1);
	L->Show(L);
	cout<<endl<<"判断是否为空："<<L->IsEmpty(L)<<endl; 
	
	L->Destroy(L); 
    cout<<endl<<"判断是否为空："<<L->IsEmpty(L)<<endl; 
}
