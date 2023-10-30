#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define ll long long
#define M 1000000007
class vertex{
    public:
        int val;
        int parent;
        int dist;
        int color;

        vertex(){}

        vertex(int v,int p,int d,int c){
            val=v;
            parent=p;
            dist=d;
            color=c;
        }

        void display() {
            cout << "Vertex{vertexId=" << val << ", distance=" << dist
                << ", color=" << color << ", predecessor=" << parent << '}';
        }
};

class Graph{
    public:
        int noOfvertex;
        vector<vertex> vertices;
        vector<vector<int> > adj;

        Graph(int n): noOfvertex(n), vertices(noOfvertex), adj(noOfvertex){
            for(int i=0;i<n;i++){
                vertices[i]=vertex(i,-1,-1,1);
            }
        }

        void addEdge(int u, int v) {
                adj[u].push_back(v);
            }

        vector<vertex>& getVertices() { 
            return vertices; 
        }

        vector<int> bfsOfGraph(int s){
            vector<int> bfs;

            for(int i=0;i<noOfvertex;i++){
                vertices[i].color=1;
                vertices[i].dist=INT_MAX;
                vertices[i].parent=-1;
            }

            vertices[s].color=2;
            vertices[s].dist=0;
            vertices[s].parent=-1;

            queue<int> q;
            q.push(s);

            while(!q.empty()){
                int f=q.front();
                q.pop();
                bfs.push_back(f);
                for(int i:adj[f]){
                    if(vertices[i].color==1){
                        vertices[i].color=2;
                        vertices[i].dist=vertices[f].dist+1;
                        vertices[i].parent=f;
                        q.push(i);
                    }
                }
                vertices[f].color=3;
            }

            return bfs;
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

    cout << "BFS traversal of the graph is as follows..." << endl;
    vector<int> bfs=graph.bfsOfGraph(0);
    for(int i:bfs){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<vertex> vertices = graph.getVertices();
    cout << "\nThe information related to BFS traversal is as follow..." << endl;
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].display();
        cout << endl;
    }
}