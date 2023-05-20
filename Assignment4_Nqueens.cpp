// N-queen Problem
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int n,map<int,bool> &rowVisited,map<int,bool> &upDaigonalVisited,map<int,bool> &downDaigonalVisited){
    if(rowVisited[row] == true || upDaigonalVisited[n-1+col-row] == true || downDaigonalVisited[row+col] == true){
        return false;
    }
    else{
        return true;
    }
}

void addSolution(vector<vector<string>> &ans,vector<vector<int>> &board){
    vector<string> ans_;
    for(int i = 0; i<board.size(); i++){
        string temp = "";
        for(int j = 0; j<board[0].size(); j++){
            if(board[i][j] == 1){
                temp+="Q";
            }
            else{
                temp+=".";
            }
            temp+="  ";
        }
        ans_.push_back(temp);
        temp = "";
    }
    ans.push_back(ans_);
}

void solve(vector<vector<int>> &board,vector<vector<string>> &ans,int col,int n,map<int,bool> &rowVisited,map<int,bool> &upDaigonalVisited,map<int,bool> &downDaigonalVisited){
    if(col == n){
        addSolution(ans,board);
        return;
    }

    for(int i = 0; i<n; i++){
    
        if(isSafe(i,col,n,rowVisited,upDaigonalVisited,downDaigonalVisited)){
            board[i][col] = 1;
            rowVisited[i] = true;
            upDaigonalVisited[n-1+col-i] = true;
            downDaigonalVisited[col+i] = true;

            solve(board,ans,col+1,n,rowVisited,upDaigonalVisited,downDaigonalVisited);

            board[i][col] = 0;
            rowVisited[i] = false;
            upDaigonalVisited[n-1+col-i] = false;
            downDaigonalVisited[col+i] = false;
        }

    }
}

int main(){
    int n;
    cout<<"Enter Number of queens : ";
    cin>>n;

    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<string>> ans;

    map<int,bool> rowVisited;
    map<int,bool> upDaigonalVisited;
    map<int,bool> downDaigonalVisited;

    solve(board,ans,0,n,rowVisited,upDaigonalVisited,downDaigonalVisited);

    for(auto i: ans){
        for(auto j:i){
            cout<<j<<endl;
        }
        cout<<endl;
    }


    return 0;
}