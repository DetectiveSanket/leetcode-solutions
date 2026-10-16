class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

  // Approach :- Prefix sum + hash map
  // Time :- O(N)
  // Space :- O(N)
        
        unordered_map<int,int> seen;
        int currSum = 0;
        int count = 0;
        seen[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            int complition = currSum - k;

            if(seen.find(complition) != seen.end()) {
                count += seen[complition];
            }

            seen[currSum]++;
        }

        return count;
    }
};