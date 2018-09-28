#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
int n, m, x, y, restaurants = 0;
int a[MAX_N]; // has cat or not
vector<int> edges[MAX_N]; // adjacency list of edges
bool visit[MAX_N]; // flag whether the vertex is visited

// Recursion to the depth first
// Check consecutive cats along the traversal
void dfs(int curr_vertex, int curr_cons_cat) {
	if(visit[curr_vertex]) return;
	visit[curr_vertex] = true;
	curr_cons_cat = a[curr_vertex] ? curr_cons_cat + 1 : 0; // If the vertex contains no cat, then the consecutive cats becomes 0, else the consecutive cats increased by 1
	if(curr_cons_cat > m) return;
	int numOfChild = 0;
	for(int i=0; i<edges[curr_vertex].size(); i++) {
		if(!visit[edges[curr_vertex][i]]) { // If visit = true, then it is the parent vertex
			dfs(edges[curr_vertex][i], curr_cons_cat);
			numOfChild++;
		}
	}
	if(numOfChild == 0) { // If numOfChild = 0, then it is the leaf vertex
		restaurants++; // Add the number of restaurant that Keya can go
	}
}

int main() {
	// Input
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		visit[i] = false; // Make vertex i unvisited
	}
	for(int i=1; i<n; i++) {
		cin >> x >> y;
		edges[x].push_back(y); // Add connection from x to y, as we don't know what vertex is the parent
		edges[y].push_back(x); // Add connection from y to x, as we don't know what vertex is the parent
	}
	// Do dfs to visit all vertices
	dfs(1, 0);
	// Output the result
	cout << restaurants << endl;
	return 0;
}