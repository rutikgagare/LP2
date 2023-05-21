// Prims Algorithm
#include<bits/stdc++.h>
using namespace std;

void prims(vector<int> &visited,vector<pair<int,int>> &mst, vector<pair<int,int>> adjList[]){

    // min heap format
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

    int p,q,w;
    for(int i = 0; i<e; i++){
        // p starting node of the edge and q is the ending node
        // w weight of the edge
        cin>>p>>q>>w;
        adjList[p].push_back({q,w});
        adjList[q].push_back({p,w});
    }

    // for avoidance of cyclic path
    vector<int> visited(v,0);

    // edges which will be the part of mst, their start and end nodes
    vector<pair<int,int>> mst;

    prims(visited,mst,adjList);

    cout<<"Edges in the minimum spanning tree : "<<endl;
    for(auto i:mst){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    return 0;
}