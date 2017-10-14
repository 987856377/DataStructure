#include<iostream>
#include<cstdlib>
#include<windows.h>
typedef char ElemType;
using namespace std;
typedef struct ListString{
	ElemType data;
	struct ListString *next;
}ListString;
void initString(ListString *&head1,ListString *&head2){
	head1 = new ListString;
	head2 = new ListString;
	head1->next=NULL;
	head2->next=NULL;
}
void StrAssign(ListString *&head1,char cstr[]){  //串从数组初始化 
	ListString *ptr=head1->next,*temp=head1;
	for(int i=0;cstr[i]!='\0';i++){
		ptr=new ListString;
		ptr->data=cstr[i];
		temp->next=ptr;
		temp=ptr;
	}
	temp->next=NULL;
}
ListString *StrCopy(ListString *&head1,ListString *&head2){      //串的拷贝 
	ListString *ptr1=head1->next;
	ListString *ptr2=head2->next,*temp=head2;
	while(ptr1){
		ptr2 = new ListString;
		ptr2->data=ptr1->data;
		temp->next=ptr2;
		temp=ptr2;
		ptr1=ptr1->next;
	}
	temp->next=NULL;
	return head2; 
}
bool isEqual(ListString *&head1,ListString *&head2){    //判断两串是否相等 
	ListString *ptr1=head1->next,*ptr2=head2->next;
	while(ptr1&&ptr2&&ptr1->data==ptr2->data){
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	if(ptr1==NULL&&ptr2==NULL){
		return true;
	}
	else{
		return false;
	}
}
int StrLenth(ListString *&head){
	int i=0;
	ListString *ptr=head->next;
	while(ptr){
		i++;
		ptr=ptr->next;
	}
	return i;
}
ListString *StrConcat(ListString *&head1,ListString *&head2){   //链接：创建一个新串将两串的数据添加到到一个新串中 
	ListString *ptr1=head1->next,*ptr2=head2->next;
	ListString *Str,*ptrS,*temp;
	Str=new ListString;
	temp=Str;
	ptrS=Str->next;
	while(ptr1){
		ptrS=new ListString;
		ptrS->data=ptr1->data;
		temp->next=ptrS;
		temp=ptrS;
		ptr1=ptr1->next;
	}
	ptrS=head2->next;
	while(ptr2){
		ptrS=new ListString;
		ptrS->data=ptr2->data;
		temp->next=ptr2;
		temp=ptr2;
		ptr2=ptr2->next;
	} 
	temp->next=NULL;
	return Str;
} 
ListString *SubStr(ListString *head1,int i,int j){ //求子串 
	ListString *Str,*ptr=head1->next,*pStr,*temp;
	int k;
	Str=new ListString;
	pStr=Str->next;
	temp=Str;
	if(i<=0||i>StrLenth(head1)||j<0||i+j-1>StrLenth(head1)){
		return Str;
	} 
	for(k=0;k<i-1;k++){
		ptr=ptr->next;
	}
	for(k=0;k<j;k++){
		pStr=new ListString;
		pStr->data=ptr->data;
		temp->next=pStr;
		temp=pStr;
		ptr=ptr->next;
	}
	temp->next=NULL;
	return Str;
}

void showString(ListString *&head){
	ListString *ptr=head->next;
	while(ptr){
		cout<<ptr->data<<"   ";
		ptr=ptr->next;
	}
} 
int main(){
	ListString *head1,*head2,*Str;
	initString(head1,head2);
	char cstr[]="abcdefg";
	cout<<"链串初始化..."<<endl;
	StrAssign(head1,cstr);
	showString(head1);
	cout<<endl<<"串长："<<StrLenth(head1)<<endl;
	
	cout<<"将进行链串的拷贝...."<<endl;
	head2=StrCopy(head1,head2);
	Sleep(1000);
	cout<<"拷贝完成：";
	showString(head2); 
	cout<<endl<<"是否相等："<<isEqual(head1,head2)<<endl; 
	
	cout<<"链串链接：";
	Str=StrConcat(head1,head2);
	showString(Str);
	
	cout<<endl<<"求子串：";
	Str=SubStr(head1,2,5);
	showString(Str);
	return 0;
} 
