/*
 *                    二分搜索适用于排序好的数组 
 */
#include<iostream>
#define N 10
using namespace std;
int binarySearch(int *a,int key){
	int low = 0;
	int high = N-1;
	while(low<=high){
		int mid = (low+high)/2;
		if(key==a[mid])
		    return mid;
		else if(key>a[mid])
		    low = mid + 1;
		else
		    high = mid - 1;		    
	}
	return -1; 
}
int main(){
	int a[N] = {1,2,3,4,5,6,7,8,9,88};
	int n;
	cout<<"请输入想要查找的数： ";
	cin>>n; 
	int result = binarySearch(a,n);
	if(result!=-1)
	    cout<<"您要找的数的下标为："<<result<<endl;
	else
	    cout<<"没有找到您想要找的数。"<<endl; 
	return 0; 
} 
