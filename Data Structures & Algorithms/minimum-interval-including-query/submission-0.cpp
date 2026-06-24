class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        int m=queries.size();
        vector<pair<int,int>> q;
        for(int i=0;i<m;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        vector<int> ans(m,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i=0;
        int n=intervals.size();
        for(auto [query,idx]:q){
            while(i<n && intervals[i][0]<=query){
                int left=intervals[i][0];
                int right=intervals[i][1];
                int len=right-left+1;
                pq.push({len,right});
                i++;
            }
            while(!pq.empty() && pq.top().second<query){
                pq.pop();
            }
            if(!pq.empty()){
                ans[idx]=pq.top().first;
            }
        }
        return ans;
    }
};
