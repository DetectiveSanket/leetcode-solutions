class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

    // Approach:- Brustforce :- Time Limit Exceeded
    // T: O(N^3);
    // S: O(N^2);

        // vector<vector<int>> res;
        // if (n < 3) return res;

        // // Use a set to handle the "unique triplets" requirement
        // set<vector<int>> tripletSet;

        // for (int i = 0; i < n - 2; i++) {
        //     for (int j = i + 1; j < n - 1; j++) {
        //         for (int k = j + 1; k < n; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 tripletSet.insert(temp);
        //             }
        //         }
        //     }
        // }

        // // Convert set back to vector
        // for (auto triplet : tripletSet) {
        //     res.push_back(triplet);
        // }
        // return res;

// -------------------------------------------------------------------// 

    // Approach:- Two Pointer :
    // T: O(n^2logn);
    // S: O();
        //     sort(nums.begin(), nums.end());
        //     vector<vector<int>> res;
        //     set<vector<int>> tripletSet;


        //     for(int i = 0; i < n - 2; i++) {
        //         int left = i + 1;
        //         int right = n-1;

        //         while(left < right) {
        //             int sum = nums[i] + nums[left] + nums[right];

        //             if(sum == 0) {
        //                 tripletSet.insert({nums[i], nums[left], nums[right]});
        //                 right--;
        //                 left++;  
        //             }

        //             else if(sum > 0) {
        //                 // left++;
        //                 right--;
        //             }

        //             else {
        //                 // right--;
        //                 left++;
        //             }
        //         }
        //     }

        // for (auto triplet : tripletSet) {
        //     res.push_back(triplet);
        // }
        // return res;    

    // -------------------------------------------------------------------// 

    // Approach:- Two Pointer :
    // T: O(N^2);
    // S: O(N);

            vector<vector<int>> res;
            sort(nums.begin(), nums.end()); // Crucial for Two-Pointers
            for (int i = 0; i < n - 2; i++) {
                // Skip duplicates for the first element
                if (i > 0 && nums[i] == nums[i-1]) continue;

                int left = i + 1;
                int right = n - 1; // Start from the very end

                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == 0) {
                        res.push_back({nums[i], nums[left], nums[right]});
                        // Skip duplicates for left and right pointers
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    } else if (sum < 0) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        return res;    
    }
};