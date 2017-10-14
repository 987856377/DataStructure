#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct Info{
	char Id[20];
	char Password[20];
	struct Info *next;
}Info;
/*
		读取账号密码信息 
*/          
void Loading(Info *&Head){
	Info *ptr = Head->next,*temp = Head;
	
	fstream iofile;
	iofile.open("c:/information.txt",ios::in | ios::app);
	while(!iofile.eof()){
		ptr = new Info;
		iofile.getline(ptr->Id,20);
		iofile.getline(ptr->Password,20);
		temp->next=ptr;
		temp=ptr;
	}
	temp->next=NULL;
	iofile.close();
}
/*
		验证账号 
*/ 
bool TestId(Info *&Head,char *str){
	Info *ptr = Head->next;
	while(ptr){
		if(strcmp(str,ptr->Id)==0){			
			return true;
		}
		ptr=ptr->next;
	}
	return false;
}
/*
		验证密码 
*/
bool TestPassword(Info *&Head,char *str){
	Info *ptr = Head->next;
	while(ptr){
		if(strcmp(str,ptr->Password)==0){			
			return true;
		}
		ptr=ptr->next;
	}
	return false;
}
/*
		注册账号 
*/
bool Apply(Info *&Head){
	Loading(Head);                      //先载入账号密码信息 
	Info *ptr = Head->next,*temp = Head;
	
	ofstream outfile;
	outfile.open("c:/information.txt",ios::app);
	
	char id[20],password1[20],password2[20];
	while(1){
		cout<<"请输入要注册的账号：";
		cin>>id;
		if(TestId(Head,id)){             //验证账号是否已被注册过			
			cout<<"账号已被注册"<<endl;
		}
		else{
			ptr = new Info;
			strcpy(ptr->Id,id);
			cout<<endl<<"请输入密码：";
			cin>>password1;
			int count=3;
			while(count--){
				cout<<endl<<"请再次输入密码：";
				cin>>password2;
				if(strcmp(password1,password2)==0){
					strcpy(ptr->Password,password2);
					outfile<<ptr->Id<<endl;             //  如果账号没被注册
					outfile<<ptr->Password<<endl;       //  两次输入的密码均正确
					ptr->next=NULL;                     //  向文件中写入账号密码 
					cout<<"注册成功"<<endl;
					getchar();
					return true;
				}
				else{
					if(count==0)
						cout<<"您多次输入的密码错误，请重新注册"<<endl;
					else
						cout<<"两次密码不匹配，请重新输入"<<endl;	
				}				
			}
		}
		break;
	}
	outfile.close();
	getchar();
	return false;	
}

bool Login(Info *&Head){
	Loading(Head);
	char id[20],password[20];
	cout<<"请输入账号：";
	cin>>id;
	if(TestId(Head,id)){                             //验证账号是否已被注册过
		cout<<"账号正确"<<endl;
		int count=3;
		while(count--){
			cout<<"请输入密码："; 
			cin>>password;
			if(TestPassword(Head,password)){         //验证密码是否正确 
				cout<<"密码正确，欢迎使用"<<endl;
				getchar();
				return true;
			}
			else{
				if(count==0)
					cout<<"您多次输入的密码错误，请核实后登录"<<endl;
				else
					cout<<"两次密码不匹配，请重新输入"<<endl;
			}
		}		 
	}
	else{
		cout<<"请输入已注册的账号"<<endl;
		getchar();
		return false; 
	}	
}

void Menu(Info *&Head){
	system("cls");
	cout<<"请选择："<<endl;
	cout<<"1.注册"<<endl;
	cout<<"2.登录"<<endl;
	cout<<"3.退出"<<endl; 
	int choose;
	cin>>choose;
	switch(choose){
		case 1:Apply(Head);
		    break;
		case 2:Login(Head);
		    break;
		case 3:
			cout<<"欢迎再次使用"<<endl;
			getchar();
	    	exit(0);
		default:
		 	Menu(Head);		
	} 
}

int main(){
	Info *Head;
	Head = new Info;
	Menu(Head);
	return 0;
}
