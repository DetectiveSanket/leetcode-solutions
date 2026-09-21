class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1, end = -2;
        int max_val = nums[0];
        int min_val = nums[n - 1];

        for (int i = 1; i < n; i++) {
            // Forward pass: find the rightmost element smaller than max_val
            max_val = max(max_val, nums[i]);
            if (nums[i] < max_val) {
                end = i;
            }

            // Backward pass: find the leftmost element larger than min_val
            int j = n - 1 - i;
            min_val = min(min_val, nums[j]);
            if (nums[j] > min_val) {
                start = j;
            }
        }

        return end - start + 1;
    }
};