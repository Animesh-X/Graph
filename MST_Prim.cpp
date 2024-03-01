#include<iostream>
#include<utility>
#include<queue>
using namespace std;

class ComparePairs{
    public:
       bool operator()(const pair<int, pair<int, int> >& p1, const pair<int, pair<int, int> >& p2) const {
        return p1.first > p2.first; 
    }
};

void MSTPrims(vector<pair<int,int> > adj[],int n){
    int visited[n];
    memset(visited,0,sizeof(visited));
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, ComparePairs> pq;
    pq.push(make_pair(0,make_pair(0,-1)));
    vector<pair<int,pair<int,int> > > v;
    int weight=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second.first;
        int wt=it.first;
        int parent=it.second.second;
        if(visited[node]==1) continue;
        visited[node]=1;
        weight+=wt;
        v.push_back(make_pair(wt,make_pair(node,parent)));
        for(auto temp:adj[node]){
            int adjnode=temp.first;
            int edgeWeight=temp.second;
            if(!visited[adjnode]){
                pq.push(make_pair(edgeWeight,make_pair(adjnode,node)));
            }
        }
    }
    cout<<"-------MST-----------"<<endl;
    cout<<"Weight\t"<<"Node"<<"\t"<<"Parent"<<endl;
    for(auto it:v){
        cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
    }
    cout<<"Total Weight: "<<weight<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > adj[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    MSTPrims(adj,n);

}