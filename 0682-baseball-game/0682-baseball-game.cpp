class Solution {

   // Approach :- Stack
  // Time :- O(N)
  // Space :- O(N)
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;

        for(auto op : operations) {

            if(op == "+") {
                if(!st.empty() && st.size() > 1) {
                    int first = st.top();
                    st.pop();
                    int second = st.top();
                    st.push(first);

                    st.push(first + second);
                }
            }

            else if(op == "D"){
                if(!st.empty()) {
                    int prev = st.top();
                    st.push(2*prev);
                }
            }

            else if(op == "C") {
                if(!st.empty() ) {
                    st.pop();
                }
            }

            else {
                st.push(stoi(op));
            }

        }

        int sum = 0;
        while(!st.empty() ) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};