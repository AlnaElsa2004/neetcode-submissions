
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
         sort(intervals.begin(), intervals.end());
         int i=0;
         int n=intervals.size();
         int count=0;
         
        
         while (i < n) {
            vector<int> newint = intervals[i];

            while (i < n - 1 &&
                   newint[1] > intervals[i + 1][0]) {
                newint[1] = min(newint[1],
                                intervals[i + 1][1]);
                i++;
               count++;
            }

            
            i++;
        }
return count;

    }
};
