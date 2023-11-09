#include<iostream>
#include<stack>
using namespace std;

void DFS(vector<int> adj[],int n,int node,int visited[],stack<int> &st){
    visited[node]=1;
    for(int i:adj[node]){
        if(!visited[i]) DFS(adj,n,i,visited,st);
    }
    st.push(node);
}

void dfs(vector<int> adj[],int node,int visited[],vector<int> &scc){
    visited[node]=1;
    scc.push_back(node);
    for(int i:adj[node]){
        if(!visited[i]) dfs(adj,i,visited,scc);
    }
}

void SCC(vector<int> adj[],int n){      //Kosaraju's Algorithm          //O(V+E)
    int visited[n];
    memset(visited,0,sizeof(visited));
    stack<int> st;      //store the nodes in decresing order of finishing time
    for(int i=0;i<n;i++){       //O(V+E)
        if(!visited[i]){
            DFS(adj,n,i,visited,st);
        }
    }
    //Transpose the graph
    vector<int> adjTranspose[n];        //O(V+E)
    for(int i=0;i<n;i++){
        for(int j:adj[i]){
            adjTranspose[j].push_back(i);
        }
    }
    memset(visited,0,sizeof(visited));
    int scc=0;
    vector<int> components; 
    while(!st.empty()){         //O(V+E)
        int node=st.top();
        st.pop();
        if(!visited[node]){
            scc++;
            dfs(adjTranspose,node,visited,components);
            cout<<"Strongly Component "<<scc<<" :";
            for(int i:components){
                cout<<i<<" ";
            }
            components.clear();
            cout<<endl;
        }
    }
    cout<<"Total No of Strongly Connected components: "<<scc<<endl;
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
    SCC(adj,n);
}