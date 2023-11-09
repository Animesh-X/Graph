#include<iostream>
#include<stack>
using namespace std;

void dfs(vector<int> adj[],int n,int node,int visited[],stack<int> &st){
    visited[node]=1;
    for(int i:adj[node]){
        if(!visited[i]){
            dfs(adj,n,i,visited,st);
        }
        
    }
    st.push(node);
}
vector<int> topoSort(vector<int> adj[],int n){
    int visited[n];
    stack<int> st;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,n,i,visited,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
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

    for(int i=0;i<n;i++){
        cout<<i<<"--->";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<int> ans=topoSort(adj,n);
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}