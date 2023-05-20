// bfs dfs traversal

#include<bits/stdc++.h>
using namespace std;

void bfsTraversal(map<int,list<int>> adjList,vector<int> &visited,int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();

        for(auto j:adjList[temp]){
            if(visited[j] == 0){
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}

void dfsTraversal(map<int,list<int>> adjList,vector<int> & visited,int node){
    visited[node] = 1;
    cout<<node<<" ";
    for(auto i: adjList[node]){
        if(!visited[i]){
            dfsTraversal(adjList,visited,i);
        }
    }
}

int main(){

    // take input for graph
    map<int,list<int>> adjList;

    int v,e;
    cout<<"Enter Number of Vertices : ";
    cin>>v;

    cout<<"Enter Number of edges : ";
    cin>>e;

    for(int i = 0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }


    vector<int> visited(v,0);
    cout<<"BFS Traversal : ";
    for(int i = 0; i<v; i++){
        if(visited[i] == 0){
            bfsTraversal(adjList,visited,i);
        }
    }
    cout<<endl;

    vector<int> visited_(v,0);
    cout<<"DFS Traversal : ";
    for(int i = 0; i<v; i++){
        if(visited_[i] == 0){
            dfsTraversal(adjList,visited_,i);
        }
    }
    cout<<endl;

    

    return 0;
}