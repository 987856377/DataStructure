#include<iostream>
#include<cstdlib>
#include<time.h>
#define N 999
using namespace std;          //交换排序   稳定   时间复杂度  n*n 
void bubbleSort(int *a)
{
	int i,j,t;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
} 
int main()
{
	int a[N];
	srand(time(0));
	for(int i=0;i<N;i++){
		a[i] = rand()%1000;
	}
	bubbleSort(a);
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	system("pause");
	return 0;
}
