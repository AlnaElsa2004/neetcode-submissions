
class Solution {
public:

    void dfs(int src,vector<bool>& vis,vector<vector<int>> &edges){
        vis[src]=true;
        
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];
               if (u == src || v == src) {
                // neighbor is whichever endpoint isn't 'src'
                int neighbor = (u == src) ? v : u;

                if (!vis[neighbor]) {
                    dfs(neighbor, vis,edges); 
            }
        }}
       
    }
    int countComponents(int n, vector<vector<int>>& edges) {
      vector<bool> vis(n,false);
      //if (edges.size() != n - 1)
        //    return false;
        int connected=0;
      for(int i=0;i<n;i++){
         if (!vis[i]) {
          dfs(i, vis, edges);  // marks all nodes in this component
        connected++;                     // only then count it as one component
    }
      }
      return connected;
    }
};
