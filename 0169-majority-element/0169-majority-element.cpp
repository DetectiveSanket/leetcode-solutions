class Solution {
public:
    int majorityElement(vector<int>& nums) {

  // Approach :- Hashing
  // Time :- O(N);
  // Space :- O(N);  

        int n = nums.size();
        int majority = n / 2;

        unordered_map<int , int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int ans = INT_MIN;

        for(int i = 0; i < n ; i++) {

            int no = nums[i];
            // cout << "count : " << mp[no] << endl;

            if(mp.find(no) != mp.end() && majority < mp[no]) {
                if(ans < mp[no]) {
                    ans = no;
                }
            }
        }

        return ans;
        
    }
};