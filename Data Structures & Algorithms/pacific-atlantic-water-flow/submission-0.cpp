class Solution {
public:

   vector<vector<int>> height;
   int rows,cols;
   void dfs(int r,int c,vector<vector<bool>>& visit,int prevht){
    if(r<0 ||c<0|| r>=rows|| c>=cols || visit[r][c] || height[r][c]<prevht){
        return;
    }
    visit[r][c]=true;
    dfs(r+1,c,visit,height[r][c]);
    dfs(r-1,c,visit,height[r][c]);
    dfs(r,c+1,visit,height[r][c]);
    dfs(r,c-1,visit,height[r][c]);
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        height=heights;
        rows=height.size();
        cols=height[0].size();
        vector<vector<bool>> pac(rows,vector<bool>(cols,false));
        vector<vector<bool>> atl(rows,vector<bool>(cols,false));
        for(int c=0;c<cols;c++){
            dfs(0,c,pac,height[0][c]);
            dfs(rows-1,c,atl,height[rows-1][c]);
        }
        for(int r=0;r<rows;r++) {
            dfs(r,0,pac,heights[r][0]);
            dfs(r,cols-1,atl,heights[r][cols-1]);
        }
        vector<vector<int>> res;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pac[r][c] && atl[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};
