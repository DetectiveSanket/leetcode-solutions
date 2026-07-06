class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
  //T: O(N^2);
  //S: O(1);      
        // int n = nums.size();
        // for(int i = 0; i < n - 1; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[i] + nums[j] == target) {
        //             return {i , j};
        //         }
        //     }
        // }

        // return {};

  //T: O(N);
  //S: O(1);

        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            int completion = target - nums[i];

            if(map.find(completion) != map.end()) {
                return {map[completion] , i};
            }

            map[nums[i]] = i;

        }
        return {};
        
    }
};