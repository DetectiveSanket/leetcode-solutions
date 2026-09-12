class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

// Approach :- brute-force approach (Time Limit Exceeded )
// Time :- O(N^2)
// Space :- O(N);

        int n = temperatures.size();
        // vector<int> ans(n , 0);

        // for(int i = 0; i < n; i++) {

        //     int curr = temperatures[i];
        //     int x = i + 1;
        //     int count = 1;

        //     while(x < n) {
        //         if(curr < temperatures[x]) {
        //             ans[i] = count;
        //             break;
        //         }

        //         count++;
        //         x++;
        //     }
        // }

        // return ans;


// Approach :- Monotonic stack
// Time :- O(N)
// Space :- O(N);


        vector<int> ans(n , 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                ans[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }

        return ans;
    }
};