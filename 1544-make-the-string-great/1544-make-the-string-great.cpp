class Solution {
public:
    string makeGood(string s) {

  // Approach :- Stack
  // Time :- O(N);
  // Space :- O(N);

        string res = "";

        for(char ch : s) {
            if(!res.empty() && abs(res.back() - ch) == 32 ) {
                res.pop_back();
            }
            else {
                res.push_back(ch);
            }
        }
        
        // stack<char> st;

        // for(int i = 0; i < s.length(); i++) {
        //     char ch = s[i];
        //     if(st.empty() ) {
        //         st.push(ch);
        //     }

        //     else if(abs(st.top() - ch) == 32) {
        //         st.pop();
        //     }

        //     else {
        //         st.push(ch);
        //     }
        // }

        // string res = "";
        // while(!st.empty()){
        //     res.push_back(st.top());
        //     st.pop();
        // }

        // reverse(res.begin(), res.end());
        // return res;

        return res;
    }
};