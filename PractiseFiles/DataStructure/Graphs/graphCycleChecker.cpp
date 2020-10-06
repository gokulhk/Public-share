#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;


template<typename T> //to make code more generic and accept graphs of wide range of datatypes 

class Graph{

	map< T, list<T>> adjacency_list;

public:

	void addEdge(T start_vertex, T end_vertex){

		adjacency_list[start_vertex].push_back(end_vertex);

		//assuming all edges are bidirectional and non weighted.
		adjacency_list[end_vertex].push_back(start_vertex);
	}

	bool cycle_helper(T current_vertex, map<T, bool> &visited, T parent){

		//mark current node as visited
		visited[current_vertex] = true;
		cout<<"Just Visited : " << current_vertex<<endl; //for understanding

		for( T nbr : adjacency_list[current_vertex]){

			if( !visited[nbr] ){
				bool cycle_exists = cycle_helper( nbr, visited, current_vertex);

				if(cycle_exists) return true;
			}
			else if( nbr != parent){
				return true;
			}
		}

		return false;
	}

	bool contains_cycle(T source_vertex){

		//map for tracking visited vertices
		map<T, bool> visited;
		for( auto node : adjacency_list){
			T current_node = node.first;
			visited[current_node] = false;
		}

		//call helper cycle checker sub routine
		return cycle_helper(source_vertex, visited, -1); // -1 indicates default parent node value for source vertex

	}

};


int main(){

	Graph<int> g;

	//add all edges of graph
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);


	//print BFS order of given graph
	if(g.contains_cycle(0)){
		cout<<"Yes, given graph contains cycle.";
	}
	else{
		cout<<"No, given graph doesn't contain cycle.";
	}

	return 0;
}