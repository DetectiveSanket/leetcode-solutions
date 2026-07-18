class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

   // Approach:- Two pointer
   // T:- O(N^2);
   // S:- O(1);
   
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans = INT_MAX;
        int res = 0;

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);
 
                if(diff < ans) {
                    ans = diff;
                    res = sum;
                }

                // One line track
                // if (abs(sum - target) < ans) {
                //     ans = abs(sum - target);
                //     res = sum;
                // }

                if (sum < target) {
                    left++;
                } 
                else if (sum > target) {
                    right--;
                } 
                else {
                    // If sum == target, it's the closest possible
                    return sum;
                }

            }
        }

        return res;
    }
};