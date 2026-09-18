class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
  // Approach :- Brust force approach
  // Time :- O(N^2) = Time Limit Exceeded
  // Space :- O(N)

        int n = heights.size();
        // vector<int> ans;


        // for(int i = 0; i < n - 1; i++) {
        //     int greater = i + 1;
        //     int count = 1;

        //     for(int j = greater + 1; j < n; j++ ) {
        //         if(heights[i] < heights[greater] ) {
        //             break;
        //         }
        //         else if(heights[greater] < heights[j]) {
        //             greater = j;
        //             count++;
        //         }
        //     }
        //     ans.push_back(count);
        // }

        // ans.push_back(0);
        // return ans;

  // Approach :- monotonic stack 
  // Time :- O(N)
  // Space :- O(N)

        vector<int> ans(n , 0);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            int visible_count = 0;

            while(!st.empty() && heights[i] > st.top() ) {
                st.pop();
                visible_count++;
            }

            if(!st.empty()) {
                visible_count++;
            }

            ans[i] = visible_count;
            st.push(heights[i]);
        }

        return ans;
    }
};