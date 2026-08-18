#include <string>
#include <stack>
#include <sstream>

class Solution {

  // Approach :- Stack
  // Time :- O(N)
  // Space :- O(N)

public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;

        // Process tokens using stack
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(token);
            }
        }

        if (st.empty()) return "/";

        // Stack pops in reverse order, so prepend to build canonical path
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result;
    }
};