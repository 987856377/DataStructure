#include<iostream>
#include<cstdlib>
#include<time.h>
#define N 99999
using namespace std;          //交换排序   不稳定   时间复杂度  n*log n 

int Division(int Array[],int low,int high){
	while(low < high){
		int baseNum = Array[low];
		
		while(low < high){
			if(baseNum > Array[high]){
				Array[low] = Array[high];
				break;
			}
			high--;
		}
		
		while(low < high){
		    if(baseNum < Array[low]){
		    	Array[high] = Array[low];
				break;  
			}
			low++;
		}
		Array[low] = baseNum;
	}
	return low;
}

void QuickSort(int Array[],int low,int high){
	if(low < high){
		int flag = Division(Array,low,high);
		QuickSort(Array,low,flag);
		QuickSort(Array,flag+1,high);
	}
}

int main(){
	int Array[N];
	srand(time(0));
	for(int i=0;i<N;i++){
		Array[i] = rand()%100;
	}
	QuickSort(Array,0,N-1);
	for(int i = 0 ; i < N ; i ++ ){
		cout<<Array[i]<<"  ";
	}
	cout<<endl;
	return 0;
} 
