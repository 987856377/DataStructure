#include<iostream>
#include<stdlib.h>
#define MAX 99
typedef int ElemType;
using namespace std;

typedef struct Node{
	int adjvex;
	struct Node *next;
}EdgeNode;

typedef struct VertexNode{
	ElemType vertex;
	EdgeNode *firstarc;
}VertexNode,AdjList[MAX];

typedef struct ALGraph{
	AdjList adjlist;
	int numVertex,numEdge;
}ALGraph;

typedef struct Queue{
	ElemType data;
	struct Queue *next;
}Queue;

typedef struct LinkQueue{
	Queue *front;
	Queue *rear;
}LinkQueue;

void InitQueue(LinkQueue *&Q){
	Q= new LinkQueue;
	Q->front=Q->rear=NULL;	
}
void EnQueue(LinkQueue *&Q,ElemType data){
	
    Queue *p= new Queue;
	p->data=data;
	p->next=NULL;
	if(Q->front==NULL){
		Q->front=p; 
	}
	else{
		Q->rear->next=p;
	    Q->rear=p;
	}	
}

bool isEmpty(LinkQueue *&Q){
	return Q->front==Q->rear;
}

bool DeQueue(LinkQueue *&Q,ElemType &data){
	Queue *ptr;
	ptr = Q->front;
	data = ptr->data;
	if(Q->front==Q->rear){
		Q->front=Q->rear=NULL;
	}else{
	    Q->front = ptr->next;
	}
	free(ptr);
	return true;
}

int Location(ALGraph *&G,int vertex){
	int i;
	for(i=0;i<G->numVertex;i++){
		if(vertex==G->adjlist[i].vertex){
			return i;
		}
	}
	if(i==G->numVertex){
		exit(1);
	}
	return 0;
}

void CreateGraph(ALGraph *&G){
	
	int i,j,k;
	EdgeNode *ptr;
	cout<<"请输入顶点数和边数：";
	cin>>G->numVertex>>G->numEdge;
	
	cout<<"请输入顶点编号：";
	for(i=0;i<G->numVertex;i++){
		cin>>G->adjlist[i].vertex;
		G->adjlist[i].firstarc=NULL;
	} 
	
	ElemType v1,v2;
	cout<<"请输入每条边的顶点：";
	for(k=0;k<G->numEdge;k++){
		
		cin>>v1>>v2;
		i=Location(G,v1);
		j=Location(G,v2);
		
		ptr = new EdgeNode;
		ptr->adjvex = j;
		ptr->next = G->adjlist[i].firstarc;
		G->adjlist[i].firstarc = ptr;
	}
}
void ShowGraph(ALGraph *&G){  
    int i;  
    EdgeNode *p;  
    cout<<"下面把图的逻辑存储打印出来:"<<endl;
	
    for(i=0;i<G->numVertex;i++){
	  
        cout<<G->adjlist[i].vertex;  
        p=G->adjlist[i].firstarc;    
        while(p){  
            cout<<"->"<<p->adjvex;  
            p=p->next;  
        }  
        cout<<endl;  
    }     
}

bool visited[MAX];

bool DFS(ALGraph *&G,int i){
	
	EdgeNode *ptr = G->adjlist[i].firstarc;
	
	cout<<G->adjlist[i].vertex<<"  ";
	
	visited[i]=true;                       
	
	while(ptr){
		if(!visited[ptr->adjvex]){
			DFS(G,ptr->adjvex);
		}
		ptr=ptr->next;
	}
	return true;
} 

bool DFSTraverse(ALGraph *&G){
	for(int i=0;i<G->numVertex;i++){
		visited[i]=false;        //初始化为全都没有被遍历过 
	}
	
	for(int i=0;i<G->numVertex;i++){
		if(!visited[i]){
			DFS(G,i);
		}
	}
}

bool BFSTraverse(ALGraph *&G){
	LinkQueue *Q;
	int i;
	for(i=0;i<G->numVertex;i++){
		visited[i] = false;
	}
	InitQueue(Q);
	 
	for(i=0;i<G->numVertex;++i){
		
		if(!visited[i]){
			
			EnQueue(Q,i);
			
			while(!isEmpty(Q)){
				
				int data;
				
				DeQueue(Q,data);
				
				visited[data]=true;
				
				cout<<G->adjlist[data].vertex<<"  ";
				
				EdgeNode *ptr = G->adjlist[data].firstarc;
				
			    while(ptr){
			    	
			    	if(!visited[ptr->adjvex]){
			    		EnQueue(Q,ptr->adjvex);
					}
					
					ptr= ptr->next;
				}
			}
		}
	}
	return true;
}
int main(){                      // 5 5  1 2 3 4 5 1 2 2 3 3 4 4 5 5 1
	
	ALGraph *G;
	G = new ALGraph;
	
	CreateGraph(G);
	
	ShowGraph(G);
	
	cout<<"深度优先遍历：";
	DFSTraverse(G);
	
	cout<<endl<<"广度优先遍历：";
	BFSTraverse(G); 
	return 0;
} 
