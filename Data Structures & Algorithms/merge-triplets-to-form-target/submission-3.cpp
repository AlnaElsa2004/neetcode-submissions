class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> tar = {0, 0, 0};

        for (auto &t : triplets) {
            // Ignore invalid triplets
            if (t[0] > target[0] ||
                t[1] > target[1] ||
                t[2] > target[2])
                continue;

            tar[0] = max(tar[0], t[0]);
            tar[1] = max(tar[1], t[1]);
            tar[2] = max(tar[2], t[2]);
        }

        return tar == target;
    }
};