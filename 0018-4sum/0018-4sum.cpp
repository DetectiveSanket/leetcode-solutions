class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
  //A: Two Pointer.      
  //T: O(N^3);
  //S: O(N^2);    
    
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> arr;

        for(long long int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(long long int j = i + 1; j < n - 2; j++) {
                if(j >  i + 1 && nums[j] == nums[j - 1]) continue;

                long long int left = j + 1;
                long long int right = n - 1;

                while (left < right) {

                   long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target) {
                        arr.push_back({ nums[i] , nums[j] , nums[left] , nums[right] });

                        //check for duplicate
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }

                    else if(sum < target) {
                        left++;
                    }

                    else {
                        right--;
                    }
                }
            }
        }

        return arr;
    }
};