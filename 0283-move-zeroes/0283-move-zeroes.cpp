class Solution {
public:
    void moveZeroes(vector<int>& nums) {

   // Approach :- Two pointer
   // Time :- O(N)
   // Space :- O(1)

        int left = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[left] , nums[i]);
                left++;
            }
        }
    }
};