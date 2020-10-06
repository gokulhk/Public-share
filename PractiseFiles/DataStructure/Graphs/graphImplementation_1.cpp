/*

Works on:
	- Bidirectional Edge Graphs
	- Non-Weighted Edges 
	- Integer Labelled Vertices
	- Uses list data structure to implement Adjacency list implementation of Given Graph

*/

#include <iostream>
#include <list>

using namespace std;

class Graph{

	int vertex_count ;
	list<int> *adjacency_list;

public:
		Graph(int vertex_count){
			this->vertex_count = vertex_count;
			adjacency_list = new list<int>[vertex_count];
		}

		void addEdge(int start_vertex, int end_vertex){
			adjacency_list[start_vertex].push_back(end_vertex);
			adjacency_list[end_vertex].push_back(start_vertex);
		}

		void printGraph(){

			for(int vertex = 0 ; vertex < vertex_count ; ++vertex){
				cout<<"vertex : " << vertex << " -> ";
				for(int weight : adjacency_list[vertex]){
					cout<<weight<<" ";
				}
				cout<<endl;
			}

		}
};

int main(){

	//Instantiating Graph Object
	Graph  G(4);

	//Adding Edges of the Graph
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,2);
	G.addEdge(2,3);

	//Display Grpah
	G.printGraph();

	return 0;
}