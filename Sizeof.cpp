/*
           sizeof和strlen的区别：		   
		   sizeof  计算的是空间 
		   strlen  计算的是长度 
*/
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
typedef struct info{
	int data;
	struct info *next;
}info; 
int main()
{
	char a[88]="jfha";
	int *p = (int*)malloc(10*sizeof(int));
	int *q = new int;
	cout<<sizeof(q)<<endl;
	cout<<sizeof(p)<<endl; 
	cout<<"sizeof: "<<sizeof(a)<<endl;
	cout<<"strlen: "<<strlen(a)<<endl;
	cout<<sizeof(int)<<endl; 
	cout<<"info structure: "<<sizeof(info)<<endl;
	return 0;
}
