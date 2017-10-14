#include<iostream>
#include<stdlib.h>
#define N 7
using namespace std;
typedef int ElemType;

typedef struct Node{
	
	ElemType data;
	struct Node *next;
}Node,*pNode;

typedef struct Hash{
	Node *first;
}Hash; 

Hash *InitHash(Hash *&hash,int num){
	hash = new Hash;
    if(!hash){
    	cout<<"Error"<<endl;
    	exit(1);
	}
    for(int i = 0;i< num;i++){
    	hash[i].first = NULL;
	}
    return hash;
}

Node *Search(Hash *hash,ElemType data){
	if(!hash){
		return NULL;
	}
	Node *ptr = hash[data%N].first;
	
	while(ptr&&ptr->data!=data){
	
	    ptr = ptr->next;
	}
	return ptr;

}

bool Insert(Hash *&hash,ElemType data){
	if(Search(hash,data)){
		cout<<"此数据已存在。"<<endl;
		return false;
	}
	Node *ptr = hash[data%N].first;
	Node *temp = new Node;
	if(!temp){
		cout<<"分配空间失败。"<<endl;
		return false;
	}
	temp->data = data;
	temp->next = NULL;
	if(!ptr){
		hash[data%N].first = temp;
	}else{
		while(ptr->next){
		    ptr = ptr->next;
		}
		ptr->next = temp ;
	}
	return true;
	
}

bool Delete(Hash *&hash,ElemType data){
	if(!Search(hash,data)){
		cout<<"数据不存在。"<<endl;
		return false;
	}
    Node  *ptr = hash[data%N].first;
    Node *temp=ptr;
    if(data==ptr->data){
    	
    	hash[data%N].first = ptr->next;
    	cout<<"删除元素："<<ptr->data<<"成功"<<endl;
    	return true;
	}
	else{
		while(ptr){
			temp = ptr;
			if(data==ptr->data){
				temp->next=ptr->next;
				cout<<"删除元素："<<ptr->data<<"成功"<<endl; 
				free(ptr);
				return true;
			}			
			
			ptr = ptr->next;
		}
	}
	
}

int main(){
	
	Hash *hash;Node *node;
	int num;
	cout<<"输入要初始化多少数据:";
	cin>>num;
	InitHash(hash,num); 
	cout<<"初始化完成。。。"<<endl;
	
	cout<<"下面将插入数据：\n";

	if(Insert(hash,8)){
		cout<<"插入元素 8 完成"<<endl;
	}else{
		cout<<"插入元素 8 失败"<<endl;
	}
	
	if(Insert(hash,15)){
		cout<<"插入数据 15 完成"<<endl;
	}else{
		cout<<"插入数据 15 失败"<<endl;
	}
	                                 
	if(Insert(hash,3)){
		cout<<"插入数据 3 完成"<<endl;
	}else{
		cout<<"插入数据 3 失败"<<endl;
	}
	 
	int data;
	cout<<"请输入要查找的数据：";
	cin>>data; 
	if(Search(hash,data)){
		cout<<"查找的数据存在"<<endl;
	}else{
		cout<<"查找的数据不存在"<<endl;
	}
	
	int data1;
	cout<<"请输入要删除的数据:";
	cin>>data1;
	Delete(hash,data1);
	return 0;
}





