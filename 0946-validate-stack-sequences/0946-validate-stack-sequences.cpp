class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

  // Approach :- Basic Stack
  // Time :- O(N)
  // Space :- O(N)

        stack<int> st;
        int j = 0;

        for(int i = 0; i < pushed.size(); i++) { // for(auto i : pushed)

            st.push(pushed[i]); // st.push(i);

            while(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};