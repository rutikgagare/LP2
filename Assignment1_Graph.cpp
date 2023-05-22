// bfs dfs traversal

#include<bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<int> adjList[],vector<int> &visited,int node){
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

void dfsTraversal(vector<int> adjList[],vector<int> & visited,int node){
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

    int v,e;
    cout<<"Enter Number of Vertices : ";
    cin>>v;

    cout<<"Enter Number of edges : ";
    cin>>e;

    vector<int> adjList[v];

    int p,q;
    for(int i = 0; i<e; i++){
        cin>>p>>q;
        adjList[p].push_back(q);
        adjList[q].push_back(p);
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