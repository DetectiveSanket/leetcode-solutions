class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
  // Approach :- monotonic stack 
  // Time :- O(N)
  // Space :- O(N)    
        int n = prices.size();
        stack<int> st;
        vector<int> ans = prices;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && prices[i] <= prices[st.top()]) {
                ans[st.top()] = prices[st.top()] - prices[i] ;
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};