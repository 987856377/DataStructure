#include<iostream>
#include<cstdlib>
#include<time.h>
#define N 99999
using namespace std;        //  选择排序  不稳定   时间复杂度  n*log n 

void HeapAdjust(int *Array,int start,int end){
	int temp = Array[start];
	int i = 2*start+1;
	while(i<=end){
		if(i+1<=end&&Array[i+1]>Array[i]){
			i++;
		}
		if(Array[i]<=temp){
			break;
		}
		Array[start] = Array[i];
		start = i;
		i = 2*start+1;
		
	}
	Array[start] = temp;
}

void HeapSort(int *Array){
	int i=0;
	
	for(i=N/2;i>=0;i--){
		HeapAdjust(Array,i,N-1);
	}
	
	for(i=N-1;i>0;i--){
		int temp = Array[i];
		Array[i] = Array[0];
		Array[0] = temp;
		
		HeapAdjust(Array,0,i-1);
	}
	
}

int main(){
	srand(time(0));
	int i=0;
	int Array[N];
	for(i=0;i<N;i++){
		Array[i]=rand()%100;
	}
	
	HeapSort(Array);
	
	for(i=0;i<N;i++){
		cout<<Array[i]<<"  ";
	}
	cout<<endl; 
	return 0;
}
