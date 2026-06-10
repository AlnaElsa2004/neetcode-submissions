class Solution {
public:
    bool search(vector<vector<char>>& board, string word,int r, int c,int i,vector<vector<bool>>& visited){
        if(i==word.size()){
            return true;
        }
        if(r<0 || r >= board.size() ||
            c < 0 || c >= board[0].size()|| word[i]!=board[r][c]){
            return false;
        }
        if(visited[r][c]==true){
            return false;
        }
        visited[r][c]=true;
       bool found= search(board,word,r+1,c,i+1,visited)||
        search(board,word,r-1,c,i+1,visited)||
        search(board,word,r,c+1,i+1,visited)||
        search(board,word,r,c-1,i+1,visited);
        visited[r][c]=false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
         for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (search(board, word, r, c, 0, visited))
                    return true;
            }
        }

        return false;
    }
};
