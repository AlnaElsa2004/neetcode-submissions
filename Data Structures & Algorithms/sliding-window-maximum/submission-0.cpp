class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        int n = nums.size();

        int left = 0;

        for(int right = k - 1; right < n; right++) {

            int maxi = *max_element(nums.begin() + left,
                                    nums.begin() + right + 1);

            result.push_back(maxi);

            left++;
        }

        return result;
    }
};
