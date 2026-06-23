/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
         auto asc=[](Interval a, Interval b){
            return a.start<b.start;
        };
        sort(intervals.begin(),intervals.end(),asc);
        int n=intervals.size();
        int i=0;
        while(i<n){
            while(i<n-1 && intervals[i].end>intervals[i+1].start){
                return false;
            }
            i++;
        }
        return true;
    }
};
