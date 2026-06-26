class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for(auto &t: times){
            int u=t[0];
            int v=t[1];
            int w=t[2];
            edges[u].push_back({v,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        minheap.push({0,k});
        unordered_set<int> visit;
        int t=0;
        while(!minheap.empty()){
            auto [w1,n1]=minheap.top();
            minheap.pop();
            if(visit.count(n1)){
                continue;
            }
            visit.insert(n1);
            t=max(t,w1);
            for(auto &[n2,w2]: edges[n1]){
                if(!visit.count(n2)){
                    minheap.push({w1+w2,n2});
                }
            }
        }
        return visit.size()==n?t:-1;
    }
};
