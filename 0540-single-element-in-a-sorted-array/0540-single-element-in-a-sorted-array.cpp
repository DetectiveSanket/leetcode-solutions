class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

/*      
   Time: O(N);

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
*/

  // Approach :- Binary search
  // Time :- O(log N);
  // Space :- O(1);

        int left = 0;
        int right = n - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if(mid % 2 == 1) {
                mid--;
            }

            if(nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            }
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};