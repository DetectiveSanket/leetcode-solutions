class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s; // Single character or empty string is a palindrome
        }

        // dp[i][j] will be true if s[i...j] is a palindrome
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        int max_len = 1;
        int start_index = 0;

        // Base cases: single characters are palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Base cases: two characters
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                if (2 > max_len) { // Check if this is the new longest
                    max_len = 2;
                    start_index = i;
                }
            }
        }

        // Fill for lengths 3 to n
        for (int length = 3; length <= n; ++length) {
            // i is the starting index of the substring
            for (int i = 0; i <= n - length; ++i) {
                // j is the ending index of the substring
                int j = i + length - 1;

                // Check if outer characters match AND inner substring is a palindrome
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (length > max_len) { // Check if this is the new longest
                        max_len = length;
                        start_index = i;
                    }
                }
            }
        }

        return s.substr(start_index, max_len);
        
    }
};