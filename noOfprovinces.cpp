#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

void dfs(int start,int visited[],vector<int> adj[]){
    visited[start]=1;
    for(auto it:adj[start]){
        if(visited[it]!=1){
            dfs(it,visited,adj);
        }
    }
}

int numProvinces(vector<int> adj[],int n){
    int visited[n+1];
    int count=0;
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            count++;
            dfs(i,visited,adj);
        }
    }
    return count;
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
    cout<<numProvinces(adj,n);
    return 0;
}