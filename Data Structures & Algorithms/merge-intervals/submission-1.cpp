class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());
         int i=0;
         int n=intervals.size();
         vector<vector<int>> ans;
         while(i<n-1 && intervals[i][1]< intervals[i+1][0]){
            ans.push_back(intervals[i]);
            i++;
         }
         while (i < n) {
            vector<int> newint = intervals[i];

            while (i < n - 1 &&
                   newint[1] >= intervals[i + 1][0]) {
                newint[1] = max(newint[1],
                                intervals[i + 1][1]);
                i++;
            }

            ans.push_back(newint);
            i++;
        }
return ans;

    }
};
