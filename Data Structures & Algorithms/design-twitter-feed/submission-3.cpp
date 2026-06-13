class Twitter {
public:

    int timer;

    unordered_map<int, unordered_set<int>> following;

    unordered_map<int, vector<pair<int,int>>> tweets;
    // {timestamp, tweetId}

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    void follow(int followerId, int followeeId) {
    if (followerId != followeeId)
        following[followerId].insert(followeeId);
}

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> newsFeed;

        priority_queue<vector<int>> pq;
        // {timestamp, tweetId, userId, index}

        if (!tweets[userId].empty()) {

            int idx = tweets[userId].size() - 1;

            pq.push({
                tweets[userId][idx].first,
                tweets[userId][idx].second,
                userId,
                idx
            });
        }

        for (int followee : following[userId]) {

            if (tweets[followee].empty())
                continue;

            int idx = tweets[followee].size() - 1;

            pq.push({
                tweets[followee][idx].first,
                tweets[followee][idx].second,
                followee,
                idx
            });
        }

        while (!pq.empty() && newsFeed.size() < 10) {

            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            newsFeed.push_back(tweetId);

            idx--;

            if (idx >= 0) {

                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return newsFeed;
    }
};