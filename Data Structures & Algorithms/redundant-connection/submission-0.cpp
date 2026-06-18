class Solution {
public:
     vector<int> parent;
        vector<int> rank;
        int find(int x){
            if(parent[x]==x){
                return x;
            }
            return parent[x]=find(parent[x]);
        }

        void Union(int x,int y){
            int px=find(x);
            int py=find(y);
            if(px==py){
                return;
            }
            if(rank[px]==rank[py]){
                parent[py]=px;
                rank[px]++;
            }else if(rank[px]<rank[py]){
                parent[px]=py;
            }else{
                parent[py]=px;
            }
        }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &edge: edges){
            int u=edge[0];
            int v=edge[1];
            if(find(u)==find(v)){
                return edge;
            }
            Union(u,v);
        }
        return {};
    }
};
