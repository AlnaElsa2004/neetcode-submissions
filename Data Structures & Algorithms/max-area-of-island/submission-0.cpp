
class Solution {
public:

    int dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>> &grid,int n, int m){

        if(i<0||j<0||i>=n||j>=m||vis[i][j]||grid[i][j]!=1){
            return 0;
        }
        vis[i][j]=true;
        return 1+dfs(i-1,j,vis,grid,n,m)+
        dfs(i+1,j,vis,grid,n,m)+
        dfs(i,j-1,vis,grid,n,m)+
        dfs(i,j+1,vis,grid,n,m);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
       
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area=dfs(i,j,vis,grid,n,m);
                    maxi=max(maxi,area);
                }
            }
        }
        return maxi;
    }
};
