#include <iostream>  
using namespace std;  
typedef struct BiTree{
	int data;
	struct BiTree *Lchild,*Rchild;
}BiTree,*BiNode;

bool Insert(BiTree *&Root,int data){
	
	if(Root==NULL){
		BiNode ptr;
		ptr=new BiTree;
		ptr->data=data;
		ptr->Lchild=NULL;
		ptr->Rchild=NULL;
		Root=ptr;
		return true;	
	}
	else if(data<Root->data){
	   return Insert(Root->Lchild,data);
	}
	else{
		return Insert(Root->Rchild,data);
	}
	return false;
}
void Init(BiTree *&Root){
	Root=NULL;
	int i,n;
	cout<<"Number Sort: ";
	cin>>n;
	int data[n];
	cout<<"\nplease input:";
	for(i=0;i<n;i++){
		cin>>data[i];
		Insert(Root,data[i]);
	}
}
void InOrder(BiTree *&Root){
	if(Root){
		InOrder(Root->Lchild);
		cout<<Root->data<<"  ";
		InOrder(Root->Rchild); 
	}
}
int main(){
	BiNode Root;
	Init(Root);
	InOrder(Root);
	cout<<endl;
	Insert(Root,9);
	InOrder(Root);
	return 0;
}





