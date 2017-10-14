#include<iostream>
#include<time.h>
#include<cstdlib>
#define N 99999
using namespace std;           //插入排序   稳定    时间复杂度  n*n 

void insertSort(int a[N])//也可以使用指针进行参数传递  void insertSort(int *a)
{
	int i,j;                  //这种排序方式比下面这种快 4~6秒   测试数据十万个 
	for(i=1;i<N;i++)
	{   
		int temp = a[i];
		for(j = i-1;j>=0&&temp<a[j];j--){
	        a[j+1] = a[j];
	    }
	    a[j+1] = temp;
	}
} 

int main()
{
	int a[N];
	srand(time(0));
	for(int i=0;i<N;i++){
		a[i] = rand()%100;
	}
    insertSort(a);
    for(int i=0;i<N;i++)
    {
    	cout<<a[i]<<"  ";
	}
	return 0;
} 

