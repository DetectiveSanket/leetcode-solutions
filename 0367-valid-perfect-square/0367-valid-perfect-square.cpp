class Solution {
public:
    bool isPerfectSquare(int num) {

  // Approach :- Binary Search
  // Time :- O(log N);
  // Space :- O(1);      

        int left = 1;
        int right = num;

        while(left <= right) {

            int mid = left + (right - left) / 2;
            long long int sqr = (long long)mid * mid;

            if(num == sqr) {
                return true;
            }

            else if (num < sqr) {
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return false;
    }
};