class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        int left = 0, right = 0;
        int count = t.length(); // chars still needed
        int minLen = INT_MAX, start = 0;

        while (right < s.length()) {
            // Expand: if current char is needed, decrement count
            if (freq[s[right]] > 0) count--;
            freq[s[right]]--;
            right++;

            // Shrink: once window is valid, try to minimize it
            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                // Remove leftmost char from window
                freq[s[left]]++;
                if (freq[s[left]] > 0) count++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};