class Solution {
public:

    bool iscycledfs(int src,vector<bool>& vis, int parent,vector<vector<int>> &edges){
        vis[src]=true;
        
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];
               if (u == src || v == src) {
                // neighbor is whichever endpoint isn't 'src'
                int neighbor = (u == src) ? v : u;

                if (!vis[neighbor]) {
                    if (iscycledfs(neighbor, vis, src, edges)) {
                        return true;
                    }
                } else if (neighbor != parent) {
                    // visited and not our parent → cycle detected
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
      vector<bool> vis(n,false);
      if (edges.size() != n - 1)
            return false;
      for(int i=0;i<n;i++){
         if (!vis[i]) {
        if(iscycledfs(i,vis,-1,edges)){
            return false;
        }
         }
      }
      return true;
    }
};
