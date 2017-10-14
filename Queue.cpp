#include<iostream>
#include<cstdlib>
#include<time.h>
#define N 10
using namespace std;

class Queue{
	private:
		int data;
		Queue *next;
		Queue *front;
		Queue *rear;
	public:
		void Init(Queue *&Q);
		bool IsEmpty(Queue *&Q);
		bool EnQueue(Queue *&Q,int data);
		bool DeQueue(Queue *&Q);
		void Show(Queue *&Q);
		void Destroy(Queue *&Q);
}; 

void Queue::Init(Queue *&Q){
	Q = new Queue;
	Q->front=Q->rear=NULL;
}

bool Queue::IsEmpty(Queue *&Q){
	return Q->front->next==NULL;
}

bool Queue::EnQueue(Queue *&Q,int data){
	Queue *ptr=new Queue;
	ptr->data=data;
	ptr->next=NULL;
	if(Q->front==NULL){
		Q->front=Q->rear=ptr;
	}else{
		Q->rear->next=ptr;
		Q->rear=ptr;
	}
	return true;
}

bool Queue::DeQueue(Queue *&Q){
	Queue *ptr=Q->front;
	if(IsEmpty(Q)) {
		return false;
	} else if(Q->front==Q->rear) {
		Q->front=Q->rear=NULL;
	} else {
		Q->front=Q->front->next;
	}
	free(ptr);
	return true;
}

void Queue::Show(Queue *&Q){
	Queue *ptr=Q->front->next;
	while(ptr){
		cout<<ptr->data<<"  "; 
		ptr=ptr->next;
	} 
}

void Queue::Destroy(Queue *&Q){
	Queue *ptr=Q->front->next;
	while(ptr){
		free(Q);
		Q=ptr;
		ptr=ptr->next;
	}
}
int main(){
	Queue *Q;
	srand(time(0));
	Q->Init(Q);
	
	cout<<"入队：";
	for(int i=0;i<N;i++){
		Q->EnQueue(Q,rand()%100);
	}
	Q->Show(Q);
	cout<<endl<<"是否为空："<<Q->IsEmpty(Q)<<endl; 
	
	cout<<"出队后：";
	Q->DeQueue(Q);
	Q->Show(Q);
	return 0;
} 
