class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (string &w : wordDict) {
                int len = w.length();

                if (i + len <= n && s.substr(i, len) == w) {
                    dp[i] = dp[i + len];
                }

                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};