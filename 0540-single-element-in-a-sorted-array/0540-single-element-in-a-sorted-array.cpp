class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        if(n < 2) {
            return nums[0];
        }

        for(int i = 0; i < n; i += 2) {

            if(i == n - 1) {
                return nums[i];
            }
            int f = i + 1;

            if(nums[i] != nums[f]) {
                return nums[i];
            }
        }
        return 0;
    }
};