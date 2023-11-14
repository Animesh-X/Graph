#include<iostream>
#include<queue>
using namespace std;

bool checkBFS(vector<int> adj[],int start,int n,int color[]){
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int nodeColor=color[node];
        for(auto i:adj[node]){
            if(color[i]==-1){
                color[i]=!nodeColor;
                q.push(i);
            }
            else if(color[i]==nodeColor){       //adjacent node having same color
                return false;
            }
        }
    }
    return true;
}

bool isBipartiteBFS(vector<int> adj[],int n){
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(checkBFS(adj,i,n,color)==false){
                return false;
            }
        }
    }
    return true;
}

bool checkDFS(vector<int> adj[],int col,int start,int color[]){
    color[start]=col;
    for(auto it:adj[start]){
        if(color[it]==-1){
            if(checkDFS(adj,!col,it,color)==false) return false;
        }
        else if(color[it]==col){      // adjacent node has the same color
            return false;
        }
    }
    return true;
}

bool isBipartiteDFS(vector<int> adj[],int n){
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(checkDFS(adj,0,i,color)==false) return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isBipartiteDFS(adj,n)){
        cout<<"Graph is Bipartite"<<"\n";
    }
    else {
        cout<<"Graph is not Bipartite"<<"\n";
    }
}