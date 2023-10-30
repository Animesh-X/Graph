#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void DFS(vector<int> adj[],int node,int visited[],vector<int> &dfs){
    visited[node]=1;
    dfs.push_back(node);
    for(auto it:adj[node]){
        if(visited[it]!=1){
            DFS(adj,it,visited,dfs);
        }
    }
}

vector<int> dfsOfGraph(vector<int> adj[],int n){
    int visited[n+1];
    memset(visited,0,sizeof(visited));
    vector<int> dfs;
    DFS(adj,1,visited,dfs);
    return dfs;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dfs=dfsOfGraph(adj,n);
    for(int i:dfs){
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}