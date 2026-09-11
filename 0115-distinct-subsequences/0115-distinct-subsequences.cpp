class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n) return 0;

        // dp[j] stores the number of distinct subsequences of s forming t[0...j-1]
        vector<unsigned long long> dp(n + 1, 0);

        // Base case: empty t has 1 match
        dp[0] = 1;

        for (int i = 1; i <= m; ++i) {
            // Traverse backwards to avoid overwriting values needed in the same step
            for (int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return (int)dp[n];
    }
};