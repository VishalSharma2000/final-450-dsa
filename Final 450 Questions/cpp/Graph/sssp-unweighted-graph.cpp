/* Find single source shortest path (SSSP) for unweighted graph */
#include <bits/stdc++.h>
using namespace std;

/* Maintain a visited array, but this works here only bcoz we are doing bfs on an unweighted graph */
void SSSP(vector<int> adj[], int V, int src) {
    vector<bool> visited(V, false);
    vector<int> parent(V);
    vector<int> distance(V, 0);
    queue<int> q;
    
    for(int i=0; i<V; i++) parent[i] = -1;
    
    q.push(src);
    visited[src] = true;
    distance[src] = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
            
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                parent[v] = u;

                q.push(v);
            }
        }
    }
    
    cout << "All Shortest Path are: " << endl;
    for(int i=0; i<V; i++) {
        int node = i;
        
        vector<int> path;
        while(node != -1) {
            path.push_back(node);
            node = parent[node];
        }
        cout << "Path from 0 to " << i << ": ";
        for(int m=path.size()-1; m>=0; m--) cout << path[m] << " ";
        cout << endl;
    }
}

/* If we don't maintain a visited array, hence checking all the paths */
void SSSP(vector<int> adj[], int V, int src) {
    vector<int> parent(V);          // to print the path
    vector<int> distance(V, INT_MAX);     // to store the minimum distance

    /* Intially no one is parent */
    for(int i=0; i<V; i++) parent[i] = -1;

    queue<int> q;
    distance[src] = 0;

    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
            
        for(int v : adj[u]) {
            if(distance[u] + 1 < distance[v]) {
                distance[v] = distance[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    int e, v;
    cin >> v >> e;
    
    vector<int> adj[v];
    for(int i=0; i<e; i++) {
        int u1, u2;
        cin >> u1 >> u2;
        adj[u1].push_back(u2);
        // adj[u2].push_back(u1);
    }
    
    for(int i=0; i<v; i++) {
      cout << i << "->";
      for(int u : adj[i]) {
        cout << u << " ";
      }
      cout << endl;
    }

    SSSP(adj, v, 0);
}

/*
Test Input:
8 8
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 0
0->1 
1->2 
2->3 
3->4 
4->5 
5->6 
6->7 
7->0 
All Shortest Path are: 
Path from 0 to 0: 0 
Path from 0 to 1: 0 1 
Path from 0 to 2: 0 1 2 
Path from 0 to 3: 0 1 2 3 
Path from 0 to 4: 0 1 2 3 4 
Path from 0 to 5: 0 1 2 3 4 5 
Path from 0 to 6: 0 1 2 3 4 5 6 
Path from 0 to 7: 0 1 2 3 4 5 6 7
*/