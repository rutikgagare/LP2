// Prims Algorithm
#include<bits/stdc++.h>
using namespace std;

void prims(vector<int> &visited,vector<pair<int,int>> &mst, vector<pair<int,int>> adjList[]){

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    // start node
    pq.push({0,{0,-1}}); // weight node parent

    while(!pq.empty()){
        pair<int,pair<int,int>> temp = pq.top();
        pq.pop();

        int weight = temp.first;
        int node = temp.second.first;
        int parent = temp.second.second;

        cout<<weight<<" "<<node<<" "<<parent<<endl;

        if(visited[node] == 1){
            continue;
        }

        visited[node] = 1;
        if(parent != -1){
            mst.push_back({parent,node});
        }

        for(auto i:adjList[node]){
            if(!visited[i.first]){
                int weight_ = i.second;
                int node_ = i.first;

                pq.push({weight_,{node_,node}});
            }
        }
    }

}

int main(){
    int v,e;
    cout<<"Enter number of vertices : ";
    cin>>v;

    cout<<"Enter number of edged : ";
    cin>>e;
    
    vector<pair<int,int>> adjList[v];

    for(int i = 0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    vector<int> visited(v,0);
    vector<pair<int,int>> mst;

    prims(visited,mst,adjList);

    cout<<"Edges in the minimum spanning tree : "<<endl;
    for(auto i:mst){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    return 0;
}