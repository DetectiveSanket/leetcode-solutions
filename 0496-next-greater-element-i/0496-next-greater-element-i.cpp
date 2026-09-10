class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

  // Approach :- Monotonic Stack
  // Time :- O(M+N)
  // Space :- O(N)   

        unordered_map<int , int> mp;
        stack<int> st;

        for(int n : nums2) {
            while(!st.empty() && n > st.top()) {
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        while(!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }



        vector<int> ans;
        for(auto i : nums1) {
            ans.push_back(mp[i]);  
        }

        return ans;
    }
};