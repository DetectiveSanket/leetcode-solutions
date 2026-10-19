class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
  // Approach :- Two Pointer
  // Time :- O(N)
  // Space :- O(1) 

        int left = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[left] != nums[i]) {
                left++;
                nums[left] = nums[i];
            }
        }
        return left + 1;
    }
};