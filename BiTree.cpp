#include <iostream>  
using namespace std;  
typedef struct BiTree{
	int data;
	struct BiTree *Lchild,*Rchild;
}BiTree,*BiNode;

BiNode Insert(BiTree *&Root,int data){
	
	if(Root==NULL){
		BiNode ptr;
		ptr=new BiTree;
		ptr->data=data;
		ptr->Lchild=NULL;
		ptr->Rchild=NULL;
		Root=ptr;	
	}
	else if(data<Root->data){
	   Root->Lchild=Insert(Root->Lchild,data);
	}
	else if(data>Root->data){
		Root->Lchild=Insert(Root->Rchild,data);
	}
	return Root;
}

BiTree *Find(BiTree *&Root,int data){       //二叉树的查找  递归算法 
	if(NULL==Root||data==Root->data){
		return Root;      //找到，返回在二叉树中的位置 
	}
	else if(data<Root->data){
		Root->Lchild=Find(Root->Lchild,data);
	}
	else if(data>Root->data){
		Root->Rchild=Find(Root->Rchild,data);
	}
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
	int data;
    cout<<endl<<"请输入要查找的数据：";
    cin>>data;
    Root=Find(Root,data);
    cout<<endl<<"Find: "<<Root->data<<"  Address: "<<Root<<endl; 
	return 0;
}
