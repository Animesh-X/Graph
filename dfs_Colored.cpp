#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

class Vertex{
    public:
        int value;
        int dTime;
        int fTime;
        int color;
        int parent;

        Vertex() {}

        Vertex(int v,int dt,int ft,int c,int p){
            value=v;
            color=c;
            dTime=dt;
            fTime=ft;
            parent=p;
        }

        void display(){
            cout << "Vertex{vertexId=" << value << ", discoveryTime=" << dTime
             << ", finishingTime=" << fTime << ", color=" << color
             << ", predecessor=" << parent << '}';
        }
};

class Graph{
    public: 
        int noOfVertices;
        vector<Vertex> vertices;
        vector<vector<int> > adj;
        int time;
        
        Graph (int n): noOfVertices(n), vertices(noOfVertices), adj(noOfVertices) {
            for(int i=0;i<n;i++){
                vertices[i]=Vertex(i,-1,-1,1,-1);
            }
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
        }

        vector<Vertex>& getVertices() { 
            return vertices; 
        }

        vector<int> dfs(){
            vector<int> dfS;
            for(int i=0;i<noOfVertices;i++){
                vertices[i].color=1;
                vertices[i].dTime=-1;
                vertices[i].fTime=-1;
                vertices[i].parent=-1;
            }
            time=0;
            dfs_visit(dfS,0);
            return dfS;
        }

        void dfs_visit(vector<int> &v,int s){
            v.push_back(s);
            time=time+1;
            vertices[s].dTime=time;
            vertices[s].color=2;
            for(int i:adj[s]){
                if(vertices[i].color==1){
                    vertices[i].parent=s;
                    dfs_visit(v,i);
                }
            }
            vertices[s].color=3;
            time=time+1;
            vertices[s].fTime=time;
        }
};

int main(){
    int n = 5;
    Graph graph(n);

    graph.addEdge(0, 1); graph.addEdge(1, 0);
    graph.addEdge(0, 2); graph.addEdge(2, 0);

    graph.addEdge(1, 3); graph.addEdge(3, 1);

    graph.addEdge(2, 3); graph.addEdge(3, 2);
    graph.addEdge(2, 4); graph.addEdge(4, 2);

    graph.addEdge(3, 4); graph.addEdge(4, 3);

    vector<int> dfs=graph.dfs();
    for(int i:dfs){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<Vertex> vertices = graph.getVertices();

    cout << "\nThe information related to DFS traversal is as follow..." << endl;
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].display();
        cout << endl;
    }
    return 0;
}