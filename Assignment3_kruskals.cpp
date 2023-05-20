// Kruskals

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void kruskals( priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq,vector<int> &visited,vector<pair<int,int>> &mst){

    while(!pq.empty()){
        pair<int,pair<int,int>> temp = pq.top();
        pq.pop();

        int node1 = temp.second.first;
        int node2 = temp.second.second;

        cout<<node1<<node2<<endl;

        if(visited[node1] && visited[node2]){
            continue;
        }
        
        visited[node1] = 1;

        mst.push_back({node1,node2});
    }
}

int main(){
    int v,e;
    cout<<"Enter number of vertices : ";
    cin>>v;

    cout<<"Enter number of edged : ";
    cin>>e;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    for(int i = 0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        pq.push({w,{u,v}});
    }

    vector<int> visited(v,0);
    vector<pair<int,int>> mst;

    kruskals(pq,visited,mst);

    cout<<"Edges in the minimum spanning tree : "<<endl;
    for(auto i:mst){
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}