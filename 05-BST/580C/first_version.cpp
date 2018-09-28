#include <bits/stdc++.h>
using namespace std;

// Notes: & in parameter is a reference
// Recursion to the depth first
// Check consecutive cats along the traversal
void dfs(int curr_vertex, int parent_vertex, vector< vector<int> > &edges, vector<int> &cat, int curr_cons_cat, int m, int &restaurants) {
	curr_cons_cat = cat[curr_vertex] ? curr_cons_cat + 1 : 0; // If the vertex contains no cat, then the consecutive cats becomes 0, else the consecutive cats increased by 1
	if(curr_cons_cat > m) return;
	int numOfChild = 0;
	for(int i=0; i<edges[curr_vertex].size(); i++) {
		if(edges[curr_vertex][i] != parent_vertex) { // If it is the parent vertex, then no need to traverse there anymore
			dfs(edges[curr_vertex][i], curr_vertex, edges, cat, curr_cons_cat, m, restaurants);
			numOfChild++;
		}
	}
	if(numOfChild == 0) { // If numOfChild = 0, then it is the leaf vertex
		restaurants++; // Add the number of restaurant that Keya can go
	}
}

int main() {
	const int MAX_N = 1e5 + 5;
	int n, m, x, y, restaurants = 0;
	vector<int> a(MAX_N); // has cat or not
	vector< vector<int> > edges(MAX_N); // adjacency list of edges

	// Input
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<n; i++) {
		cin >> x >> y;
		edges[x].push_back(y); // Add connection from x to y, as we don't know what vertex is the parent
		edges[y].push_back(x); // Add connection from y to x, as we don't know what vertex is the parent
	}
	// Do dfs to visit all vertices
	dfs(1, -1, edges, a, 0, m, restaurants);
	// Output the result
	cout << restaurants << endl;
	return 0;
}