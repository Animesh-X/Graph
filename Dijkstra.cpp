#include<iostream>
#include<queue>
#include<climits>
#include<set>
#include<algorithm> // Added for min_element
using namespace std;

vector<int> dijkstraPriorityQueue(vector<vector<int> > adj[], int n, int src){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];
            if (dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push(make_pair(dist[adjNode], adjNode));
            }
        }
    }
    return dist;
}

vector<int> dijkstraSet(vector<vector<int> > adj[], int src, int n){
    set<pair<int, int> > s;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    s.insert(make_pair(0, src));
    while (!s.empty()){
        auto minPair = *min_element(s.begin(), s.end());
        int node = minPair.second;
        int dis = minPair.first;
        s.erase(minPair);
        for (auto it : adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];
            if (dis + edgeWeight < dist[adjNode]){
                if (dist[adjNode] != INT_MAX) s.erase(make_pair(dist[adjNode], adjNode));
                dist[adjNode] = dis + edgeWeight;
                s.insert(make_pair(dist[adjNode], adjNode));
            }
        }
    }
    return dist;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj[n];
    vector<vector<int> > edges;

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp(3);
        temp[0] = u;
        temp[1] = v;
        temp[2] = w;
        edges.push_back(temp);
    }

    for (auto it : edges){
        vector<int> temp(2);
        temp[0] = it[1];
        temp[1] = it[2];
        adj[it[0]].push_back(temp);

        temp[0] = it[0];
        temp[1] = it[2];
        adj[it[1]].push_back(temp);
    }

    vector<int> dist = dijkstraPriorityQueue(adj, n, 0);
    for (int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;

    vector<int> dist1 = dijkstraSet(adj, 0, n);
    for (int i = 0; i < n; i++){
        cout << dist1[i] << " ";
    }
    cout << endl;

    return 0;
}
