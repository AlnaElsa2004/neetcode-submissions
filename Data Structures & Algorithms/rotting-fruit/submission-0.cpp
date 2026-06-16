class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==2){
                    q.push({r,c});
                }else if(grid[r][c]==1){
                    fresh++;
                }
            }
        }
        int minute=0;
        if(fresh==0) return 0;
        vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty() && fresh>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();
                q.pop();
                for(auto & [dr,dc]: directions){
                    int nr=r+dr;
                    int nc=c+dc;
                    if(nr<0 || nc<0 || nr>=row || nc>=col || grid[nr][nc]!=1){
                        continue;
                    }
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});
                }
            }
            minute++;
        }
        return fresh==0? minute:-1;
    }
};
