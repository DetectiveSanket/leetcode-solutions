class Solution {

  // Approach :- Binary Search
  // Time :- O(log N)
  // Space :- O(1)

private:

    // first occurance
    int firstOcc(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while(left <= right) {

            int mid = left + (right - left ) / 2;

            if(nums[mid] == target) {
                ans = mid;
                right = mid - 1;
            }

            else if(nums[mid] < target) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return ans;

    }


    int lastOcc(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while(left <= right) {

            int mid = left + (right - left ) / 2;

            if(nums[mid] == target) {
                ans = mid;
                left = mid + 1;
            }

            else if(nums[mid] < target) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
       }

        return ans;
    }
    

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        if(nums.size() == 0) {
            return {-1 , -1};
        }

        int one = firstOcc(nums , target);
        int two = lastOcc(nums , target);

        ans.push_back(one);
        ans.push_back(two);
        return ans;
    }
};