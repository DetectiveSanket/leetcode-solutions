class Solution {
public:
    string reverseParentheses(string s) {

  // Approach :- Stack (Parenthesis) 
  // Time :- O(N^2)
  // Space :- O(N)

        string ans;
        stack<char> st;
        int n = s.length();

        for(auto c : s) {
            if(c != ')') {
                st.push(c);
            }
            else {
                string rev = "";
                while(st.top() != '(' ) {
                    rev += st.top();
                    st.pop();
                }
                st.pop();

                for(char ch : rev) {
                    st.push(ch);
                }
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};