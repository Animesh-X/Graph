#include<iostream>
#include<queue>
using namespace std;

int prims(vector<vector<int> > adj[], int n) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> visited(n, 0);
    pq.push(make_pair(0, 0)); //{wt,node}
    int sum = 0;
    while (!pq.empty()) {
        pair<int, int> temp = pq.top();
        pq.pop();
        int node = temp.second;
        int weight = temp.first;
        if (visited[node] == 1) continue;
        visited[node] = 1;
        sum += weight;
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edgWt = it[1];
            if (!visited[adjNode]) {
                pq.push(make_pair(edgWt, adjNode));
            }
        }
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj[n];
    vector<vector<int> > edges;

    for (int i = 0; i < m; i++) { // Added the edges
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp(3);
        temp[0] = u;
        temp[1] = v;
        temp[2] = w;
        edges.push_back(temp); 
    }

    for (auto it : edges) { // Creating the adjacency list
        vector<int> temp(2);
        temp[0] = it[1];
        temp[1] = it[2];
        adj[it[0]].push_back(temp);

        temp[0] = it[0];
        temp[1] = it[2];
        adj[it[1]].push_back(temp);
    }

    int sum = prims(adj, n);
    cout << "Minimum Weight: " << sum;
}
