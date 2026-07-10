class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
  // T: O(N^2);
  // S: O(N);

        int n = nums.size();
        vector<int> ans;

        // for(int i = 0; i < n; i++) {
        //     int res = 1;
        //     for(int j = 0; j < n; j++) {
        //         if(j == i) continue;

        //         res = res * nums[j];
        //     }
        //     ans.push_back(res);
        // }

        // return ans;

/*------------------------------------------------------*/
 // T: O(N);
 // S: O(N);

        // int product = 1;
        // for(int i = 0; i < n; i++) {
        //     product *= nums[i];
        // }

        // for(int i = 0; i < n; i++) {
        //     if(nums[i] == 0) continue;
        //     int res = product / nums[i];
        //     ans.push_back(res);
        // }

        // return ans;

/*------------------------------------------------------*/
 // T: O(N);
 // S: O(1);
        vector<int> output(n);

        // 1. Left pass: store products of all elements to the left
        output[0] = 1;
        for(int i = 1; i < n; i++) {
            output[i] = output[i - 1] * nums[i - 1];
        }

        // 2. Right pass: multiply by products of all elements to the right
        int rightP = 1;
        for(int i = n - 1; i >= 0; i--) {
            output[i] = output[i] * rightP;
            rightP *= nums[i];
        }

        return output;
    }
};