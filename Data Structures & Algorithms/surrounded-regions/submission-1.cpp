class Solution {
public:
vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int i,int j,vector<vector<char>>& board){
    int n=board.size();
    int m=board[0].size();
    if(i<0||j<0||i>=n||j>=m||board[i][j]!='O'){
        return;
    }
    board[i][j]='#';
     for(auto d : dir) {
            dfs(i + d.first, j + d.second,board);
        }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int j=0;j<m;j++){
            dfs(0,j,board);
            dfs(n-1,j,board);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,board);
            dfs(i,m-1,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};
