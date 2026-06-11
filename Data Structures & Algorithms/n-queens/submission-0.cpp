class Solution {
public:

bool issafe(vector<string> &board,int r,int c,int n){
    for(int j=0;j<n;j++){
        if(board[r][j]=='Q'){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(board[i][c]=='Q'){
            return false;
        }
    }
    for(int i=r,j=c;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=r,j=c;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void nqueens(vector<string> &board,int r,int n,vector<vector<string>> &ans){
    if(r==n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(issafe(board,r,i,n)){
            board[r][i]='Q';
            nqueens(board,r+1,n,ans);
            board[r][i]='.';
        }
    }
}

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nqueens(board,0,n,ans);
        return ans;
    }
};
