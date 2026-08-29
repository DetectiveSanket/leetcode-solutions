class Solution {
public:
    int minAddToMakeValid(string s) {

  // Approach :- stack = Parentheses
  // Time :- O(N)
  // Space :- O(N)

        // int count = 0;
        // stack<char> st;

        // for(char c : s) {

        //     if(c == '(') {
        //         st.push(c);
        //         count++;
        //     }

        //     else {
        //         if(st.empty()) {
        //             count++;
        //             continue;
        //         }
        //         else if(st.top() == '(') {
        //             st.pop();
        //             count--;
        //         }
        //     }
        // }
        // return count;

// Optimal O(1) Space Solution (No Stack)

        int open = 0;
        int add = 0;

        for(char c : s) {
            if(c == '(') {
                open++;
            }
            else {
                if(open > 0) {
                    open--;
                }
                else {
                    add++;
                }
            }
        }

        return open + add;
    }
};