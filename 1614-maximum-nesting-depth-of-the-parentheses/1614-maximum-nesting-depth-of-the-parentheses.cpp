class Solution {
public:
    int maxDepth(string s) {
  // Approach :- Stack - Parentheses
  // Time :- O(N2)
  // Space :- O(1)
        int curr_depth = 0;
        int max_depth = 0;

        for(char c : s) {

            if(c == '(') {
                curr_depth++;
                max_depth = max(curr_depth , max_depth);
            }
            else if(c == ')') {
                curr_depth--;
            }
        }

        return max_depth;
 
    }
};