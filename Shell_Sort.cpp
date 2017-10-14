#include<iostream>
#include<cstdlib>
#include<time.h>
#define N 99999
using namespace std;          //  插入排序   不稳定   时间复杂度 n*n  
void ShellSort(int *a){
	int step = N/2;
	while(step>=1){
		for(int i=step;i<N;i++){
			int temp=a[i];
			int j;
			for(j=i-step;j>=0&&temp<a[j];j=j-step){
				a[j+step]=a[j];
			}
			a[j+step]=temp;
		}
		step=step/2;
	}
}
int main(){
	int a[N];
	srand(time(0));
	for(int i=0;i<N;i++){
		a[i] = rand()%100;
	}
	ShellSort(a);
	for(int i=0;i<N;i++)
    {
    	cout<<a[i]<<"  ";
	}
	return 0;
}
