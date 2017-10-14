#include<iostream>
#include<cstdlib>
#include<time.h>
#define N 99999
using namespace std;           //合并排序   稳定   时间复杂度   n*log n   需额外空间 

void Merge(int *Array,int *tempArray,int low,int mid,int high){
	int lowEnd = mid - 1;
	int highStart = mid;     
	int tempIndex = low;               //定义临时数组的下标 
	int tempLenth = high - low + 1;    //定义临时数组长度 
	
	//先循环两个区间都没有结束的情况 
	while( (low <= lowEnd) && (highStart <= high) ){

		//例如：  左侧数组： 1         2       右侧数组：    3           4     
		//下标              low      lowEnd              highStart      high  
		//谁小将谁放入临时数组   下标自增 
		if(Array[low] < Array[highStart])//比较两数组的第一个值  low为 1 的下标   highStart为 3 的下标      
		    tempArray[tempIndex++]=Array[low++];      //   low  自增变为  lowEnd   
		else
		    tempArray[tempIndex++]=Array[highStart++]; //  highStart  自增变为  high 
	}
	
	//判断左序列是否结束 
	while( low <= lowEnd ){
		tempArray[tempIndex++] = Array[low++];
	}
	
	//判断右序列是否结束 
	while( highStart <= high ){
		tempArray[tempIndex++] = Array[highStart++];
	}
	
	//将临时数组的数据拷贝到上一层数组中 
	for(int i = 0;i < tempLenth; i++){
		Array[high] = tempArray[high];
		high--; 
	}
}

void MergeSort(int *Array,int *tempArray,int low,int high){
	if( low < high ){
		
		int mid = (low+high)/2;
		//递归划分左侧数组 
		MergeSort(Array,tempArray,low,mid);
		//地规划分右侧数组 
		MergeSort(Array,tempArray,mid+1,high);
		//数组合并操作 
		Merge(Array,tempArray,low,mid+1,high);
	}
} 

int main(){
	srand(time(0));
	int Array[N];
	for(int i=0;i<N;i++){
		Array[i]=rand()%100;
	}
	int tempArray[N];
	MergeSort(Array,tempArray,0,N-1);
	for(int i = 0;i<N;i++){
		cout<<Array[i]<<"  ";
	} 
	return 0;
} 
