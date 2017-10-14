#include<iostream>
#include<cstdlib>
#include<time.h>
#define N 99999
using namespace std;             //不稳定排序    选择排序   时间复杂度 n*n 

/*void selectSort(int *a)
{
	int i,j;
	for(i=0;i<N-1;i++)
	{
		int tempindex = i;
		for(j=i+1;j<N;j++)
		{
			if(a[tempindex]>a[j]){
				tempindex = j;
			}
		}
		if(tempindex!=i)
		{
			int tempdata = a[tempindex];
			a[tempindex] = a[i];
			a[i] = tempdata;
		}
	}
}
*/ 
void selectSort(int *a){
	int i,j;
	for(i=0;i<N-1;i++){
		for(j=i+1;j<N;j++){
			if(a[i]>a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()
{
	int a[N];
	srand(time(0));
	for(int i=0;i<N;i++){
		a[i] = rand()%100;
	}
	selectSort(a);
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0; 
 } 
