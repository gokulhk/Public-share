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

	void dfs_helper(T current_vertex, map<T, bool> &visited){

		//mark current vertex as visited 
		visited[current_vertex] = true;
 
		//visited all its neighbours if not visited and dive in!
		for(T nbr : adjacency_list[current_vertex]){

			if( ! visited[nbr]){
				dfs_helper(nbr, visited);
			}
		}

		//this point of code indicate all child nodes of current node is visited so print current and return to parent.
		cout<<current_vertex<< " ";
	}

	void dfs(T source_vertex){

		//only map DS is used to keep track of visited vertices and not fall in infinite recursion
		map<T, bool> visited;

		//intialise visited of all vertices as False
		for(auto node : adjacency_list){
			T current_vertex = node.first;
			visited[current_vertex] = false;
		}

		//call dfs_helper to do DFS
		dfs_helper(source_vertex, visited);

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
	g.dfs(0);


	return 0;
}