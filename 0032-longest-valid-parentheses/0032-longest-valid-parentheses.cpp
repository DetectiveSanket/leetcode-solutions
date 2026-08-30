class Solution {
public:
    int longestValidParentheses(string s) {

  // Approach :- Stack
  // Time :- O(N)
  // Space :- O(N) 

        int maxL = 0;
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {
                st.push(i);
            }    
            else {
                
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else {
                    maxL = max(maxL , i - st.top());
                }
            }
        }
        return maxL;
    }
};