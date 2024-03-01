#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    Vertex v;
    Node *next;

    Node(Vertex v1){
        this->v=v1;
        this->next=NULL;
    }

};

void insertAtHead(Node *&head,Vertex v);

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

        void addEdge(int u,int v){
            adj[u].push_back(v);
        }

        vector<Vertex>& getVertices() { 
            return vertices; 
        }

        Node *dfs(){
            Node *head;
            for(int i=0;i<noOfVertices;i++){
                vertices[i].color=1;
                vertices[i].dTime=-1;
                vertices[i].fTime=-1;
                vertices[i].parent=-1;
            }
            time=0;
            dfsVisit(head,0);
            return head;
        }

        void dfsVisit(Node *&head,int s){
            time=time+1;
            vertices[s].dTime=time;
            vertices[s].color=2;
            for(int i:adj[s]){
                if(vertices[i].color==1){
                    vertices[i].parent=s;
                    dfsVisit(head,i);
                }
            }
            vertices[s].color=3;
            time=time+1;
            vertices[s].fTime=time;
            insertAtHead(head,vertices[s]);
        }

};


void insertAtHead(Node *&head,Vertex v){
    Node *temp=new Node(v);
    temp->next=head;
    head=temp;
}

int main(){
    int n=9;
    Graph g(n);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,4);
    g.addEdge(5,4);
    g.addEdge(0,1);
    g.addEdge(0,1);
    g.addEdge(0,1);
    g.addEdge(0,1);
    Node *head=g.dfs();
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->v.value<<"\t";
    }
    cout<<endl;
    vector<Vertex> vertices = g.getVertices();
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].display();
        cout << endl;
    }
}