#include<iostream>
#include<cstdlib>
using namespace std; 
typedef char ElemType;    //定义char 型为ElemType 
typedef struct BiTree{
	ElemType data;
	struct BiTree *Lchild,*Rchild;
}BiTree,*BiNode;         

void CreateTree(BiTree *&Root){
	ElemType data;
	cin>>data;
	if(data=='#'){
	    Root=NULL; 
	}
	else{
		Root = new BiTree;
		Root->data=data;              //构建二叉树 
		CreateTree(Root->Lchild);
		CreateTree(Root->Rchild);
	} 
}
bool PreOrder(BiTree *&Root){        //前序遍历 
	if(NULL==Root){
		return false;
	}
	else{
		cout<<Root->data<<"   ";
		PreOrder(Root->Lchild);
		PreOrder(Root->Rchild);
	}
	return true;
}

bool InOrder(BiTree *&Root){           //中序遍历 
	if(NULL==Root){
		return false;
	}
	else{
		InOrder(Root->Lchild);
		cout<<Root->data<<"   ";
		InOrder(Root->Rchild);
	}
	return true;
}

bool PostOrder(BiTree *&Root){               //后序遍历 
	if(NULL==Root){
		return false;
	}
	else{
		PostOrder(Root->Lchild);
		PostOrder(Root->Rchild);
		cout<<Root->data<<"   ";
	}
	return true;
}

int nodeNum(BiTree *&Root){        //判断节点个数 
	if(NULL==Root){
		return 0;
	}
	else if(NULL==Root->Lchild&&NULL==Root->Rchild){
		return 1;
	}
	else{
		return ((nodeNum(Root->Lchild)+nodeNum(Root->Rchild)))+1;      //递归遍历左右子树节点个数，最后加上根节点 
	}
}

int Depth(BiTree *&Root){
	int Ldepth,Rdepth;
	if(NULL==Root){
		return 0;
	}
	else{
		Ldepth=Depth(Root->Lchild);
		Rdepth=Depth(Root->Rchild);
	}
	return (Ldepth>Rdepth?Ldepth:Rdepth)+1;    //比较左子树和右子树的深度，返回深度较大的 
}
BiTree *Insert(BiTree *&Root,ElemType data){     //在有序二叉树中插入数据   递归算法 
	
	if(NULL==Root){
		BiNode temp = new BiTree;
		temp->data=data;
		temp->Lchild=NULL;
		temp->Rchild=NULL;
		Root=temp;     //二叉树根节点为空，则此数为根 
	}
	else if(data<Root->data){
		Root->Lchild = Insert(Root->Lchild,data);   //小于根节点，递归遍历左子树插入到合适位置 
	}
	else if(data>Root->data){
		Root->Rchild = Insert(Root->Rchild,data);  //大于根节点，递归遍历插入到合适位置 
	}
	return Root;
}

BiTree *Find(BiTree *&Root,ElemType data){       //二叉树的查找  递归算法 适用于二叉排序树
	if(NULL==Root||data==Root->data){
		return Root;      //找到，返回在二叉树中的位置 
	}
	else if(data<Root->data){
		Root->Lchild=Find(Root->Lchild,data);
	}
	else{
		Root->Rchild=Find(Root->Rchild,data);
	}
}

/*
BiTree *Find(BiTree *&Root,ElemType data){         //二叉树的查找  非递归算法 
	while(NULL!=Root){
		if(data==Root->data){
			return Root;
		}
		else if(data<Root->data){
			Root=Root->Lchild;
		}
		else{
			Root=Root->Rchild;
		}
	}
	return NULL;
}
*/
BiTree *Delete(BiTree *&Root,ElemType data){       //二叉树的删除 
	BiNode tempL,tempR;
	if(NULL==Root){
		return Root;
	}
	if(data==Root->data){
		if(NULL==Root->Lchild&&NULL==Root->Rchild){
			free(Root);
			cout<<"删除成功。"<<endl;
			return NULL;
		}
		else if(NULL==Root->Rchild){
			tempL=Root;
			Root=Root->Lchild;
			free(tempL);
			cout<<"删除成功。"<<endl;
			return Root;
		}
		else if(NULL==Root->Lchild){
			tempR=Root;
			Root=Root->Rchild;
			free(tempR);
			cout<<"删除成功。"<<endl;
			return Root;
		}
		else{
			tempL=tempR=Root->Rchild;
			while(Root->Lchild!=NULL){
				tempL=Root->Lchild;
			}
			tempL->Lchild=Root->Lchild;
			free(Root);
			cout<<"删除成功。"<<endl;
			return tempR;
		}
	}
	else if(data<Root->data){
		Root->Lchild=Delete(Root->Lchild,data);
	}
	else{
		Root->Rchild=Delete(Root->Rchild,data);
	}
}
void Destroy(BiTree *&Root){    //二叉树的销毁 
	if(NULL==Root){
		return;
	}
	else{
		Destroy(Root->Lchild);
		Destroy(Root->Rchild);
		free(Root);
	}
}
int main(){                         //ABC#D##EF##G##H#I##
	BiTree *Root;
	cout<<"创建二叉树：";
	CreateTree(Root);
	
    cout<<"先序遍历：";
    PreOrder(Root);
    
    cout<<endl<<"中序遍历：";
    InOrder(Root);
    
    cout<<endl<<"后序遍历：";
    PostOrder(Root);
    
    cout<<endl<<"\n节点个数："<<nodeNum(Root)<<endl; 
    
    cout<<"\n深度："<<Depth(Root)<<endl;
    
    ElemType data1;
    cout<<"请输入要插入的数据：";
    cin>>data1;
    Insert(Root,data1);
    cout<<"先序遍历：";
    PreOrder(Root);    
    cout<<endl<<"中序遍历：";
    InOrder(Root);    
    cout<<endl<<"后序遍历：";
    PostOrder(Root);    
    cout<<endl<<"\n节点个数："<<nodeNum(Root)<<endl;     
    cout<<"\n深度："<<Depth(Root)<<endl;
    
    ElemType data2;
    cout<<endl<<"请输入要查找的数据：";
    cin>>data2;
    Root=Find(Root,data2);
    cout<<endl<<"地址为："<<Root<<endl;
    
    
    ElemType data3;
    cout<<endl<<"请输入要删除的数据：";
    cin>>data3;
    Root=Delete(Root,data3);
    cout<<"先序遍历：";
    PreOrder(Root);    
    cout<<endl<<"中序遍历：";
    InOrder(Root);    
    cout<<endl<<"后序遍历：";
    PostOrder(Root);
    
    
    Destroy(Root);
    cout<<endl<<"销毁完成。"<<endl;
	return 0;
}
