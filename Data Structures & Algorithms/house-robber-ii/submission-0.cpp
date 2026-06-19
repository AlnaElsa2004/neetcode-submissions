class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int prev2 = 0;
        int prev1 = 0;

        // Case 1: Exclude last house
        for (int i = 0; i < n - 1; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        int a2 = 0;
        int a1 = 0;

        // Case 2: Exclude first house
        for (int i = 1; i < n; i++) {
            int curr = max(a1, nums[i] + a2);
            a2 = a1;
            a1 = curr;
        }

        return max(prev1, a1);
    }
};