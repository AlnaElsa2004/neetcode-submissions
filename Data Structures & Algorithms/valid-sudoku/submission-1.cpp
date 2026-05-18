class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<unordered_set<char>> rows(9);
      vector<unordered_set<char>> col(9);
      vector<unordered_set<char>> grid(9);
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char ch=board[i][j];
            if(ch=='.') continue;
            int k=(i/3)*3+(j/3);
            if(rows[i].count(ch) || col[j].count(ch) || grid[k].count(ch)){
                return false;
            }
            rows[i].insert(ch);
            col[j].insert(ch);
            grid[k].insert(ch);
        }
      }
      return true;
    }
};
