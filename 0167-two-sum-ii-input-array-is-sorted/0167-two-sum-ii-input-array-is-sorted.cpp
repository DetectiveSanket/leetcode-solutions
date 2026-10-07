class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();  

    //T: O(n^2); -->Time Limit Exceeded
    //S: O(1);

        // for(int i = 0; i < n - 1; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(numbers[i] + numbers[j] == target) {
        //             return {i+1 , j+1};
        //         }
        //     }
        // }
        // return {};

//------------- 

       unordered_map<int,int> map;
        for(int i = 0; i < numbers.size(); i++) {
            int completion = target - numbers[i];

            if(map.find(completion) != map.end()) {
                return {map[completion] + 1 , i + 1};
            }

            map[numbers[i]] = i;

        }
        return {};

//---------------------------------------

  // Approach :-Two Pointer
  // Time :- O(N)
  // Space :- O(1)

        // vector<int> op;
        // int left = 0;
        // int right = n - 1;
        
        // while(left < right) {
        //     int sum = numbers[left] + numbers[right];

        //     if(sum == target) {
        //         return {left + 1 , right + 1};
        //     }

        //     else if(sum > target) {
        //         right--;
        //     }

        //     else {
        //         left++;
        //     }
        // }

        // return {};
    }
};