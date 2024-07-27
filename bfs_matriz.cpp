// C++ implementation of the approach
//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;


// function to add edge to the graph
void addEdge(int x,int y){
	adj[x][y] = 1;
	adj[y][x] = 1;
}

// Function to perform BFS on the graph
void bfs(int start){
	// Visited vector to so that
	// a vertex is not visited more than once
	// Initializing the vector to false as no
	// vertex is visited at the beginning
	vector<bool> visited(adj.size(), false);
	queue <int> q;
	q.push(start);

	// Set source as visited
	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q.front();

		// Print the current node
		cout << vis << " ";
		q.pop();

		// For every adjacent vertex to the current vertex
		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {

				// Push the adjacent node to the queue
				q.push(i);

				// Set
				visited[i] = true;
			}
		}
	}
}

// Driver code
int main(){
    // number of vertices
    int v = 5;


    // adjacency matrix
    adj= vector<vector<int>>(v,vector<int>(v,0));

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);

    // perform bfs on the graph
    bfs(0);
}
