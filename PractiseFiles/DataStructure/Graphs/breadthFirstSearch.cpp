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

	void bfs(T source_vertex){

		//queue DS - for storing visited vertices
		queue<T> explored;
		//map DS - to mark all visited vertices and prevent infinite loop.
		map<T, bool> visited;


		explored.push(source_vertex);
		visited[source_vertex] = true;


		//take each elem from queue then print it and include its unvisited adjacent vertices into queue
		while( ! explored.empty()){

			//popping current vertex from queue and its value
			T current_vertex = explored.front();
			explored.pop();
			cout<<current_vertex<<" ";

			//visit all its unvisited adjacent vertices
			for(auto nbr : adjacency_list[current_vertex]){

				if(! visited[nbr]){
					explored.push(nbr);
					visited[nbr] = true;
				}

			}

		}

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
	g.bfs(0);


	return 0;
}