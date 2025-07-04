#include<bits/stdc++.h>
using namespace std;
// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges
// Space Complexity: O(V) for visited array, O(V) for queue, and O(V) for the result array

vector<int> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    queue<int> q;
    vector<bool> visited(V, false);

    q.push(0);
    visited[0] = true;

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++) {
            if (!visited[adj[node][j]]) {
                visited[adj[node][j]] = true;
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}

int main() {
    // Example adjacency matrix (undirected graph)
    vector<vector<int>> adj = {
        {1, 2},  // Node 0 is connected to nodes 1 and 2
        {0, 5,7},  // Node 1 is connected to nodes 0 and 3
        {0, 3,4},  // Node 2 is connected to nodes 0 and 3
        {2},   // Node 3 is connected to nodes 1 and 2
        {2}, 
        {1,6},  
        {5,8},  
        {1,8},  
        {6,7} 
    };

    vector<int> result = bfs(adj);

    // Printing the BFS traversal
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
