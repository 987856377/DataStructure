#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct GLNode{
	int tag;
	union{
		char data;
		struct GLNode *subList;
	}subL;
	struct GLNode *next;
}GLNode;
GLNode *createGL(char *&Str){	
	GLNode *head;
	char ch=*Str++;
	if(ch!='\0'){
		head = new GLNode;
		if(ch=='('){
			head->tag=1;
			head->subL.subList=createGL(Str);
		}
		else if(ch==')'){
			head=NULL;
		}
		else if(ch=='#'){
			head=NULL;
		}
		else{
			head->tag=0;
			head->subL.data=ch;
		}
	}
	else{
		head=NULL;
	}
	ch=*Str++;
	if(head!=NULL){
		if(ch==','){
			head->next=createGL(Str);
		}
		else{
			head->next=NULL;
		}
	}
	return head;
}
void showGL(GLNode *&head){
	if(head!=NULL){
		if(head->tag==0){
			cout<<head->subL.data<<" ";
		}
		else{
			cout<<"(";
			if(head->subL.subList==NULL){
				cout<<"#";
			}
			else{
				showGL(head->subL.subList);
			}
			cout<<")";
		}
		if(head->next!=NULL){
			cout<<",";
			showGL(head->next);
		}
	}
}
int GLlenth(GLNode *&head){
	int i=0;
	GLNode *ptr;
	ptr=head->subL.subList;
	while(ptr){
		i++;
		ptr=ptr->next;
	}
	return i;
}
int GLdepth(GLNode *&head){
	GLNode *ptr;
	int max=0,dep;
	if(head->tag==0){
		return 0;
	}
	ptr=head->subL.subList;
	if(ptr==NULL){
		return 1;
	}
	while(ptr){
		if(ptr->tag==1){
			dep=GLdepth(ptr);
			if(dep>max){
				max=dep;
			} 
		}
		ptr=ptr->next;
	}
	return max+1;
}
int main(){
	GLNode *head;
	char *Str="(b,(b,a,(#),d),((a,b),c((#))))";
	head=createGL(Str);
	cout<<"创建完成..."<<endl;
	cout<<"输出：";
	showGL(head);
	cout<<endl<<"表长："<<GLlenth(head)<<endl;
	cout<<"表深："<<GLdepth(head)<<endl; 
	return 0;
} 
