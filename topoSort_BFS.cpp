#include<iostream>
#include <queue>
using namespace std;


vector<int> topoSort(vector<int> adj[],int n){
    int indegree[n];
    queue<int> q;
    memset(indegree,0,sizeof(indegree));
    vector<int> ans;
    // Calculating the indegree of each node
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    // Pushing the nodes in queue whose indegree is 0
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        // removing the node from indegree list as it is already in the topo sort
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> ans=topoSort(adj,n);
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}