// class Solution {
// public:
//     bool isMatch(string s, string p) {

//         regex pattern(p);
//         smatch matches;
        
//         if(regex_search(s, matches, pattern)) {
//             if(matches.str() == s) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {

   //T: O(M+N); 
   //S: O(M-N)    
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] is true if s[0...i-1] matches p[0...j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns like "a*", "a*b*" which can match an empty string
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Case 1: p[j-1] is a regular character or '.'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Case 2: p[j-1] is '*'
                else if (p[j - 1] == '*') {
                    // Option 1: '*' matches zero of the preceding element
                    bool zero_match = dp[i][j - 2];
                    
                    // Option 2: '*' matches one or more of the preceding element
                    bool one_or_more_match = false;
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        one_or_more_match = dp[i - 1][j];
                    }
                    
                    dp[i][j] = zero_match || one_or_more_match;
                }
            }
        }
        
        return dp[m][n];
    }
};