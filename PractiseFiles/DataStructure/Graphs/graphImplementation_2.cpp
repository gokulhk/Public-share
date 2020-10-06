/*

Works on:
	- Bidirectional Edge Graphs.
	- Weighted Edges.
	- String Labeled Vertices.
	- Uses unordered_map ds for storing vertices mapped to list data structure containing pairs of Adjacent vertex and distance or weight to reach it.
	- Adjacency list is implemented using unordered map, pair, list data structures for Given Graph.

Tutorial Source : https://www.youtube.com/watch?v=drpdVQq5-mk
Coding Blocks Youtube.

*/

#include <iostream>
#include <cstring>
#include <unordered_map>
#include <list>

using namespace std;

class Graph{

	//Adjacency List
	unordered_map<string, list<pair<string, int>>> adjacency_list;

	public :

		void addEdge(string start_vertex, string end_vertex, bool bidirectional, int weight){

			adjacency_list[start_vertex].push_back( make_pair(end_vertex, weight));

			if(bidirectional){
				adjacency_list[end_vertex].push_back( make_pair(start_vertex, weight)) ;
			} 
		}

		void printGraph(){

			for( auto p : adjacency_list ){

				string start_vertex = p.first;
				list<pair<string, int>> adjacent_nodes = p.second;

				cout<<start_vertex<<" -> ";

				for(auto neighbour : adjacent_nodes){
					string end_vertex = neighbour.first;
					int weight = neighbour.second;

					cout<<end_vertex<<" "<<weight<<", ";
				}
				cout<<endl;
			}
		}

};

int main(){

	Graph g;
	
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 30);
	g.addEdge("A", "D", false, 50);

	g.printGraph();

	return 0;
}