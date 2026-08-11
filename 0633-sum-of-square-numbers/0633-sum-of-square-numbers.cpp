class Solution {
public:
    bool judgeSquareSum(int c) {

  // Approach :- Two Pointer
  // Time :- O(sqrt{c})
  // Space :- O(1)

        long long int left = 0;
        long long int right = sqrt(c);

        while(left <= right) {
            long long int x = (left * left) + (right * right);

            if(x == c) return true;

            else if(x > c) {
                right--;
            }
            else {
                left++;
            }    
        }

        return false;
    }
};