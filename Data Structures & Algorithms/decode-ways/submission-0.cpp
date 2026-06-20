class Solution {
public:
    unordered_map<int, int> dp;

    int dfs(int i, string &s) {
        if (dp.count(i))
            return dp[i];

        if (s[i] == '0')
            return 0;

        int res = dfs(i + 1, s);

        if (i + 1 < s.size() &&
            (s[i] == '1' ||
             (s[i] == '2' && s[i + 1] <= '6'))) {
            res += dfs(i + 2, s);
        }

        return dp[i] = res;
    }

    int numDecodings(string s) {
        dp[s.size()] = 1;
        return dfs(0, s);
    }
};