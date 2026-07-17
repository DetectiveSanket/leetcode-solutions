class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n = nums.size();
  // Time Limit Exceded
  // T: O(n^2);
  // S: O(1);
        // for(int i = 0; i < n - 1; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[i] == nums[j] && abs(i - j) <= k) {
        //             return true;
        //         }
        //     }
        // }

        // return false;

// -------------------------------------------------------------------// 

  // One more bad try
        // int left = 0; 
        // int right = 1;

        // while(left < n ) {
        //     if(right < n && nums[left] == nums[right] && abs(left - right) <= k) {
        //         return true;
        //     }
        //     if(n <= right) {
        //         left++;
        //         right = left + 1;
        //     }
        //     right++;
        // }

        // return false;

// -------------------------------------------------------------------// 

  // Approach:  Hashing (map)
  // T:O(N);
  // S:O(N);

        unordered_map<int,int> seen;

        for(int i = 0; i < n; i++) {
            if(seen.find(nums[i]) != seen.end()) {

                if(i - seen[nums[i]] <= k) {
                    return true;
                }
            }

            seen[nums[i]] = i;
        }      

        return false;

// -------------------------------------------------------------------// 

        // unordered_set<int> window;
        
        // for (int i = 0; i < nums.size(); i++) {
        //     // 1. Check if the current number is already in our sliding window
        //     if (window.count(nums[i])) {
        //         return true; 
        //     }
            
        //     // 2. Add the current number to the window
        //     window.insert(nums[i]);
            
        //     // 3. If the window size exceeds k, remove the oldest element
        //     // The oldest element is at index (i - k)
        //     if (window.size() > k) {
        //         window.erase(nums[i - k]);
        //     }
        // }
        
        // return false;

    //-------------------------------------------------------------------// 

        // for(int i = 0; i < n - 2; i++) {
        //     if(nums[i] + nums[i + 1] == k && abs(i - i + 1) <= k) {
        //         return true;
        //     }
        // }

        // return false;
    }
};