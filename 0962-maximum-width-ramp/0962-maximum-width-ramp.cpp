class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
  // Approach :- Brute force approach [Time Limit Exceeded]
  // Time :- O(n^2) 
  // Space :- O(1)     

        int n = nums.size();
        int ans = 0;

        // for(int i = 0; i < n - 1; i++) {

        //     int j = n - 1;
        //     while(i < j) {
        //         if(nums[i] <= nums[j]) {
        //             ans = max(ans , j - i);
        //             break;
        //         }
        //         j--;
        //     }
        // }

        // return ans;
        

  // Approach :- monotonic stack 
  // Time :- O(n) 
  // Space :- O(n) 


        stack<int> st;
        
        // 1. build a monotonically decresing stack index
        for(int i = 0; i < n; i++) {
            while(st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        // 2. Traverse from right to left to find maximun width
        for(int j = n - 1; j >= 0; j--) {
            while(!st.empty() && nums[j] >= nums[st.top()]) {
                ans = max(ans , j - st.top());
                st.pop();
            }
        }

        return ans;
    }
};