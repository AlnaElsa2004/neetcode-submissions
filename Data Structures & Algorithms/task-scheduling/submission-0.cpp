class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> freq;

        for(char task : tasks)
            freq[task]++;

        priority_queue<int> pq;

        for(auto &p : freq)
            pq.push(p.second);

        queue<pair<int,int>> q; // {remainingFreq, availableTime}

        int time = 0;

        while(!pq.empty() || !q.empty()) {

            time++;

            if(!pq.empty()) {

                int cnt = pq.top();
                pq.pop();

                cnt--;

                if(cnt > 0) {
                    q.push({cnt, time + n});
                }
            }
            else {
                time = q.front().second;
            }

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};