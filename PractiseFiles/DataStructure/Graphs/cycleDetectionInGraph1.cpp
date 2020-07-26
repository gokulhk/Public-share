//Graph Representation - Adjacency List Representation
#include<iostream>

using namespace std;


//Node logic
struct Node{
	int data;
	struct Node *next;
};

//node creator 
struct Node* createNode(int data){

	struct Node* newNode = (struct Node*)malloc( sizeof(struct Node) );
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//insert into adjacency list logic
void addEdge(struct Node *vertexEdges[], int start, int end ){

	//create node
	struct Node* newNode = createNode(end);

	//insert node at start O(1)
	newNode->next = vertexEdges[start];
	vertexEdges[start] = newNode;
}

void printAdjacenyList(struct Node *vertexEdges[], int vertexcount){

	for (int i = 0; i < vertexcount ; ++i)
	{				
		cout<<"Node "<<i<<" : ";
		struct Node* temp = vertexEdges[i];
		while( temp ){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}

}

// bool BFT( struct Node* vertexEdges[], bool explored[], int cur){

// 	if( vertexEdges[cur] == NULL){
// 		return false;
// 	}

// 	//mark current node as visited
// 	//visited[cur] = true;

// 	//visit all neighbour of  current node
// 	struct Node* temp = vertexEdges[cur];
// 	while(temp){

// 		if( explored[temp->data] ){ //cycle detection
// 			cout<<"cycle detected first at : "<<cur<<" -> "<<temp->data<<endl;
// 			return true;
// 		}

// 		//mark  neighbour nodes as visited
// 		cout<<"visited edge : "<<cur<<" -> "<<temp->data<<endl;
// 		// visited[temp->data] = true;
// 		temp = temp->next;
// 	}

// 	//mark current node as explored
// 	explored[cur] = true;
// 	cout<<"explored node : "<<cur<<endl;

// 	//explore all neighbour of current nod
// 	temp = vertexEdges[cur];
// 	while(temp){
// 		if(BFT( vertexEdges, explored, temp->data)){
// 			return true;
// 		}
// 		temp = temp->next;
// 	}


// 	return false;
// }


bool cycleExistsBFT( struct Node* vertexEdges[], int vertexcount  ){

	//use visited array 
	//bool visited[vertexcount] = { false };
	bool explored[vertexcount] = { false };

	//call BFT sub routine 
	//return BFT(vertexEdges, explored, 0); // 0 - start node ato apply BFT

	for (int i = 0; i < vertexcount ; ++i)
	{	
		struct Node* temp = vertexEdges[i];
		while(temp){
			if( explored[temp->data] || i == temp->data ){
				//cout<<"Cycle detected at edge : "<<i<<" -> "<<temp->data<<endl;
				return true;
			}
			//cout<<"Explored edge : "<<i<<" -> "<<temp->data<<endl;
			temp = temp->next;
		}
		explored[i] =  true;
	}

	return false;
}

bool pathExistsDFS(struct Node* vertexEdges[], int start, int end){

	struct Node* temp = vertexEdges[start];
	while(temp){
		if( temp->data == end || pathExistsDFS( vertexEdges, temp->data, end ) ){
			return true;
		}
		temp = temp->next;
	}
	return false;
}


int main(){

	//get test count
	int test;
	cin>>test;

	while(test--){

		//get vertex & edge count
		int vertexcount, edgecount;
		cin>>vertexcount>>edgecount;

		//adjacency list
		struct Node *vertexEdges[ vertexcount ] ;
		for(int i=0; i<vertexcount; ++i){
			vertexEdges[i] = NULL;
		}

		//fill in adjacency list
		int start, end;
		for (int i = 0; i < edgecount  ; ++i)
		{
			cin>>start>>end;
			addEdge( vertexEdges, start, end );
		}

		//print adjacency lsit for reference
		printAdjacenyList( vertexEdges, vertexcount);

		if(cycleExistsBFT(vertexEdges, vertexcount)){
			cout<<"cycleExistsBFT"<<endl;
		}
		else{
			cout<<"Cycle doesn't exist"<<endl;
		}

		//get u,v node values
		cin>>start>>end;

		if(pathExistsDFS(vertexEdges, start, end)){
			cout<<"pathExistsDFS b/w : "<<start<<" -> "<<end<<endl;
		}
		else{
			cout<<"path doesn't ExistsDFS b/w : "<<start<<" -> "<<end<<endl;
		}


	}	
}