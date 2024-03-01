#include<iostream>
using namespace std;

class DisjointSet{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for (int i=0 ;i<=n; ++i) {
                parent[i] = i;  // all elements are initially in their own set
            }
        }

        int findUltimateParent(int node){
            if(parent[node]==node){
                return node;
            }else{
                return parent[node]=findUltimateParent(parent[node]);
            }
        }

        void unionByRank(int u,int v){
            int ulpU=parent[u];
            int ulpV=parent[v];
            if(ulpU==ulpV) return;
            if(rank[ulpU] < rank[ulpV]){
                parent[ulpU]=ulpV;
            }
            else if(rank[ulpV]<ulpU){
                parent[ulpV]=ulpU;
            }
            else{
                parent[ulpV]=ulpU;
                rank[ulpU]++;
            }
        }

        void unionBySize(int u,int v){
            int ulpU=parent[u];
            int ulpV=parent[v];
            if(ulpU==ulpV) return;
            if(size[ulpU]<size[ulpV]){
                parent[ulpU]=ulpV;
                size[ulpV]+=size[ulpU];
            }
            else{
                parent[ulpV]=ulpU;
                size[ulpU]+=size[ulpV];
            }
        }
};

void krushkal(vector<vector<int> > adj[],int n){
    vector<pair<int, pair<int, int> > > edges;
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            int adjNode=it[0];
            int weight=it[1];
            int node=i;
            edges.push_back(make_pair(weight,make_pair(node,adjNode)));
        }
    }

    DisjointSet ds(n);
    sort(edges.begin(),edges.end());
    int mstWt=0;
    vector<pair<int,pair<int,int> > > ans;
    for (auto it:edges){
        int wt=it.first;
        int adjNode=it.second.second;
        int node=it.second.first;
        if(ds.findUltimateParent(adjNode)!=ds.findUltimateParent(node)){
            mstWt+=wt;
            ds.unionBySize(node,adjNode);
            ans.push_back(make_pair(wt,make_pair(node,adjNode)));
        }
    }
    cout<<"Minimum Weight: "<<mstWt<<"\n";
    for(auto it:ans){
        cout<<it.second.first<<" "<<it.second.second<<" "<<it.first<<"\n";
    }
}

int main(){
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
    krushkal(adj,n);
    
    return 0;
}