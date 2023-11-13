#include<iostream>
using namespace std;

class DisjointSet{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);
            for (int i=0 ;i<=n; ++i) {
                parent[i] = i;  // all elements are initially in their own set
            }
        }

        int findUltimateParent(int node){
            if(parent[node]==node){
                return node;
            }else{
                return parent[node]=findUltimateParent(parent[node]);
            }
        }

        void unionByRank(int u,int v){
            int ulpU=parent[u];
            int ulpV=parent[v];
            if(ulpU==ulpV) return;
            if(rank[ulpU] < rank[ulpV]){
                parent[ulpU]=ulpV;
            }
            else if(rank[ulpV]<ulpU){
                parent[ulpV]=ulpU;
            }
            else{
                parent[ulpV]=ulpU;
                rank[ulpU]++;
            }
        }

        void unionBySize(int u,int v){
            int ulpU=parent[u];
            int ulpV=parent[v];
            if(ulpU==ulpV) return;
            if(size[ulpU]<size[ulpV]){
                parent[ulpU]=ulpV;
                size[ulpV]+=size[ulpU];
            }
            else{
                parent[ulpV]=ulpU;
                size[ulpU]+=size[ulpV];
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"Same Component"<<"\n";
    }
    else {
        cout<<"Not Same"<<"\n";
    }
    ds.unionByRank(3,7);
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"Same Component"<<"\n";
    }
    else {
        cout<<"Not Same"<<"\n";
    }
}