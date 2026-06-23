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
    int minMeetingRooms(vector<Interval>& intervals) {
     if(intervals.empty()) return 0;
     auto asc=[](Interval a, Interval b){
        return a.start<b.start;
     };
     sort(intervals.begin(), intervals.end(), asc);
      priority_queue<int, vector<int>, greater<int>> pq;
      pq.push(intervals[0].end);
      for(int i=1;i<intervals.size();i++){
        if(intervals[i].start>=pq.top()){
            pq.pop();
        }
        pq.push(intervals[i].end);
      }
      return pq.size();
    }
};
