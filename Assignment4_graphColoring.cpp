// Graph Coloring

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void graphColoring(vector<int> adjList[],int &chromaticNo,vector<int> &color){
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int currNode = q.front();
        q.pop();

        vector<bool> availableColors(chromaticNo,true);

        if(color[currNode] == -1){
            for(auto i:adjList[currNode]){
                if(color[i] != -1){
                    availableColors[color[i]] = false;
                }
                else{
                    q.push(i);
                }
            }

            int availableColor = -1;
            for(int i = 0; i<chromaticNo; i++){
                if(availableColors[i] == true){
                    availableColor = i;
                    break; 
                }
            }

            if(availableColor == -1){
                chromaticNo = chromaticNo+1;
                color[currNode] = chromaticNo-1;
            }
            else{
                color[currNode] = availableColor;
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

    vector<int> adjList[v];
    for(int i = 0; i<e; i++){
        int p,q;
        cin>>p>>q;
        adjList[p].push_back(q);
        adjList[q].push_back(p);
    }

    int chromaticNo = 0;
    vector<int> color(v,-1);

    graphColoring(adjList,chromaticNo,color);

    cout<<"Chromatic Number : "<<chromaticNo<<endl;
    for(auto i:color){
        cout<<i<<" ";
    }

    return 0;
}