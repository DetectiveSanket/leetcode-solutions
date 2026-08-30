class Solution {
public:
    int scoreOfParentheses(string s) {

  // Approach :- Stack - Parentheses
  // Time :- O(N)
  // Space :- O(N)      

        stack<int> st;
        st.push(0);

        for(char c : s) {
            if(c == '(') {
                st.push(0);
            }
            else {
                int inner = st.top();
                st.pop();

                int val = max(2 * inner , 1);
                st.top() += val;
            }
        }

        return st.top();
    }
};