class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int prev2 = 1; // dp[i - 2]
        int prev1 = 1; // dp[i - 1]

        for (int i = 2; i <= s.length(); ++i) {
            int current = 0;

            // Check single-digit decode (s[i - 1])
            if (s[i - 1] != '0') {
                current += prev1;
            }

            // Check two-digit decode (s[i - 2 ... i - 1])
            int twoDigit = stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            // Shift states forward
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};