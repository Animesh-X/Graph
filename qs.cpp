#include<iostream>
#include<queue>
#include<climits>
#include<set>
#include<algorithm>
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

    cout<<"Enter value of p and q: "<<endl;
    int p,q;
    cin>>p>>q;
    vector<int> dist1=dijkstraPriorityQueue(adj,n,p);
    for (int i=0;i<n;i++){
        cout<<dist1[i]<< " ";
    }
    cout<<endl;
    vector<int> dist2=dijkstraPriorityQueue(adj,n,q);
    for (int i=0;i<n;i++){
        cout<<dist2[i]<< " ";
    }
    int flag=0;
    cout<<endl;
    for(int i=0;i<n;i++){
        if(dist1[i]==dist2[i]){
            cout<<"Target Node: "<<i<<endl;
            flag=1;
            break;
        }
    }
    if(!flag){
        cout<<"-1"<<endl;
    }
    
    return 0;
}