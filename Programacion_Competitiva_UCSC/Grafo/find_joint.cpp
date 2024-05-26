#include<vector>
using namespace std;

void DFS(vector<vector<int>>& adj, int V, vector<bool>& visited, int i) {
    visited[i] = true;
    for (int j = 0; j < V; j++) {
        if (adj[i][j] && !visited[j]) {
            DFS(adj, V, visited, j);
        }
    }
}

int find_articulation_points(vector<vector<int>>& adj, int V) {
    int count = 0;
    vector<bool> visited(V, false);
    int initial_val = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(adj, V, visited, i);
            initial_val++;
        }
    }

    for (int i = 0; i < V; i++) {
        vector<int> copy = adj[i];
        fill(visited.begin(), visited.end(), false);
        for (int j = 0; j < V; j++) {
            adj[i][j] = adj[j][i] = 0;
        }

        int nval = 0;
        for (int j = 0; j < V; j++) {
            if (!visited[j] && j != i) {
                nval++;
                DFS(adj, V, visited, j);
            }
        }
        if (nval > initial_val) {
            count++;
        }
        adj[i] = copy;
    }
    return count;
}