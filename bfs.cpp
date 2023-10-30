#include<iostream>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

vector<int> bfsOfGraph(int v,vector<int> adj[]){
    int visited[v+1];
    memset(visited,0,sizeof(visited));
    visited[1]=1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(visited[it]!=1){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
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
    vector<int> bfs=bfsOfGraph(n,adj);
    for(int i:bfs){
        cout<<i<<" ";
    }
    return 0;
}