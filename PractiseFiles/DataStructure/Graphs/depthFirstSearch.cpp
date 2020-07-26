#include<iostream>

using namespace std;

class Queue{ //array implementation

private:
	int front, rear, count, capacity;
	int *queue;

public:
	Queue(int capacity){
		queue = new int[capacity];
		count = 0;
		front = 0;
		rear = -1;
		this->capacity = capacity;
	}

	void enqueue(int data){

		//overflow check
		if( count == capacity){
			cout<<"Queue is already full! enqueue ops failed."<<endl;
			return;
		}

		 rear = (rear + 1) % capacity;
		 queue[rear] = data;
		 ++count;
	}

	int dequeue(){
		
		//underflow check
		if(count == 0){
			cout<<"Queue is already empty! dequeue ops failed."<<endl;
			exit(EXIT_FAILURE);
		}

		int data = queue[front];
		front = (front + 1) % capacity;
		--count;
		return data;
	}

	int size(){ return count; }
};


void dfs(int[] , int**, int, int);
void dfsHelper(int[], int**, bool[], int, int);
void bfs(int[] , int**, int, int);
void bfsHelper(int[], int**, bool[], Queue&, int, int);

int main(){

	//get node count
	int nodeCount;
	cout<<"Enter node count: ";
	cin>>nodeCount;

	//to store node data
	int nodes[nodeCount]; 

	//get node data 
	for(int i=0; i<nodeCount; ++i){
		cin>>nodes[i];
	}

	//adjacency matrix to represent edges
	int **adjacency = new int*[nodeCount];
	for (int i = 0; i < nodeCount; ++i)
	{
		adjacency[i] = new int[nodeCount];
	}

	int edgeCount, nodex, nodey;
	cout<<"Enter edgeCount : ";
	cin>>edgeCount;

	//intialise adjacency matrix
	for (int i = 0; i < nodeCount ; ++i)
	{
		for (int j = 0; j < nodeCount ; ++j)
		{
			adjacency[i][j] = 0;
		}
	}


	cout<<"Enter Edge in v1, v2 pairs:"<<endl;
	for (int i = 0; i < edgeCount; ++i)
	{
		cin>>nodex;
		cin>>nodey;
		adjacency[nodex][nodey] = 1; //rowise mark
		//adjacency[nodey][nodex] = 1; //columnwise mark
	}

	cout<<"adjacency matric : "<<endl;
	for (int i = 0; i < nodeCount ; ++i)
	{
		for (int j = 0; j < nodeCount ; ++j)
		{
			cout<<adjacency[i][j]<<" ";;
		}
		cout<<endl;
	}

	dfs(nodes, adjacency, nodeCount, edgeCount);
	bfs(nodes, adjacency, nodeCount, edgeCount);
}

void dfs(int nodes[], int** adjacency, int nodeCount, int edgeCount){

	cout<<"Entered dfs"<<endl;

	//visited array to prevent infinite looping
	bool visited[ nodeCount ] = { false };

	//call original dfs helper sub routine
	dfsHelper(nodes, adjacency, visited, edgeCount, 2);

}

void dfsHelper(int nodes[], int** adjacency, bool visited[], int edgeCount, int cur){

	//cout<<"Entered dfs Helper"<<endl;

	if( visited[cur] ){ //current node already already visited
		cout<<"already vsited : "<< visited[cur]<<endl;
		return;
	}

	//mark current as visited
	cout<<"node : "<<nodes[cur]<<endl;
	visited[cur] = true;

	for (int i = 0; i < edgeCount; ++i)
	{
		if( adjacency[cur][i] == 1 &&  visited[i] != true ){ //edge exists between cur node and itr node
			dfsHelper(nodes, adjacency, visited, edgeCount, i );
		}
	}

}

void bfs(int nodes[], int** adjacency, int nodeCount, int edgeCount ){

	//visited array to prevent infinite looping
	bool visited[ nodeCount ] = { false } ;

	//queue
	Queue queue(nodeCount);

	//call original bfs helper sub routine
	bfsHelper(nodes, adjacency, visited, queue, nodeCount, 2);

}

void bfsHelper(int nodes[], int** adjacency, bool visited[], Queue& queue, int nodeCount, int cur){

	cout<<"Entered bfs Helper"<<endl;
	//mark cur node as visited and add to queue
	visited[cur] = true;
	queue.enqueue(cur);

	while( queue.size() != 0 ){

		//dequeue an elem, print and explore
		int cur =  queue.dequeue();
		cout<<"visited : "<<cur<<endl;

		for (int i = 0; i < nodeCount ; ++i)
		{
			//if edge exist mark as visited if not
			if( adjacency[cur][i] == 1 && visited[i] != true ){
				visited[i] = true;
				queue.enqueue(i);
			}

		}

	}

}