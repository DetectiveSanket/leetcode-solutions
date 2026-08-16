class Solution {

  // Approach :- Bottom-Up Dynamic Programming
  // Time :- O(M+N)
  // Space :- O(M+N)

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int minNextHP = min(dp[j], dp[j + 1]);
                dp[j] = max(1, minNextHP - dungeon[i][j]);
            }
        }

        return dp[0];
    }
};