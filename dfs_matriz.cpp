#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;


void addEdge(int x,int y){
	adj[x][y] = 1;
	adj[y][x] = 1;
}

void dfs(int start, int v){
	vector<bool> visited(v, false);
	stack <int> q;
	q.push(start);
	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q.top();
		cout << vis << " ";
		q.pop();
		for (int i = 0; i < v; i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

// Driver code
int main(){
    int v = 5;

    adj= vector<vector<int>>(v,vector<int>(v,0));

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);

    dfs(0, v);
}
