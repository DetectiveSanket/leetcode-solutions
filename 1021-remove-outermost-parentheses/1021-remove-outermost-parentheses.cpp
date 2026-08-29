class Solution {
public:
    string removeOuterParentheses(string s) {

  // Approach :- Stack - Parentheses
  // Time :- O(N)
  // Space :- O(N) 

        int open = 0;
        int close = 0;
        string ans = "";
        string temp = "";

        for(char c : s) {

            if(c == '(') {
                temp.push_back(c);
                open++;
            }

            else {
                temp.push_back(c);
                close++;
            }

            if(open == close) {
                temp.erase(0,1);
                temp.pop_back();
                ans += temp;
                temp.clear();
            }

        }

        return ans;
    }
};