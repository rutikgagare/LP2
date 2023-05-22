#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board,vector<vector<string>> &ans){
    vector<string> soln;

    for(int i = 0; i<board.size(); i++){
        string temp = "";
        for(int j = 0; j<board[0].size(); j++){
            if(board[i][j] == 1){
                temp+="Q";
            }
            else{
                temp+=".";
            }
            temp+=" ";
        }
        soln.push_back(temp);
    }
    ans.push_back(soln);
}

bool isSafe(int row,int col,int n,vector<vector<int>> &board){

    // checking whether row is safe or not
    for(int i = col; i>=0; i--){
        if(board[row][i] == 1){
            return false;
        }
    }

    // checking left up daigonal
    int row_ = row;
    int col_ = col;

    while(row_ >= 0 && col_ >= 0){
        if(board[row_][col_] == 1){
            return false;
        }
        row_--;
        col_--;
    }

    // checking left down daigonal
    row_ = row;
    col_ = col;

    while(row_ < n && col_ >= 0){
        if(board[row_][col_] == 1){
            return false;
        }
        row_++;
        col_--;
    }
    return true;
}

void solve(int col,int n,vector<vector<int>> &board,vector<vector<string>> &ans){
    if(col == n){
        addSolution(board,ans);
        return;
    }

    for(int i = 0; i<n; i++){
        if(isSafe(i,col,n,board)){
            board[i][col] = 1;
            solve(col+1,n,board,ans);
            board[i][col] = 0;
        }
    }
}

int main(){
    int q;
    cout<<"Enter number of queens : ";
    cin>>q;

    // creating 2D string type vector to store all possible solution
    vector<vector<string>> ans;
    vector<vector<int>> board(q,vector<int>(q,0));

    solve(0,q,board,ans);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<endl;
        }
        cout<<endl;
    }

    return 0;
}