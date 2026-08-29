class Solution {
public:
    int minAddToMakeValid(string s) {

  // Approach :- stack = Parentheses
  // Time :- O(N)
  // Space :- O(1)

        int count = 0;
        stack<char> st;

        for(char c : s) {

            if(c == '(') {
                st.push(c);
                count++;
            }

            else {
                if(st.empty()) {
                    count++;
                    continue;
                }
                else if(st.top() == '(') {
                    st.pop();
                    count--;
                }
            }
        }
        return count;
    }
};