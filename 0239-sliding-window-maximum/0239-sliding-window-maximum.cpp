class Solution {
public:
    // Approach :- Monotonic Decreasing Deque (storing indices)
    // Time :- O(N)
    // Space :- O(k)
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Remove indices that are out of the current window bound [i - k + 1, i]
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove indices whose corresponding values are less than nums[i]
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current element index to the deque
            dq.push_back(i);

            // Once the first window of size k is reached, add front to the result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};