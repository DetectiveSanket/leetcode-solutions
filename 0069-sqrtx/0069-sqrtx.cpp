class Solution {
public:
    int mySqrt(int x) {

  // Approach :- Binary Search
  // Time :- O(log N);
  // Space :- O(1);

        if (x == 0) {
            return 0;
        }

        int left = 1;
        int right = x;
        int res = 0;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            //long long int sqr = (long long)mid * mid;

            if(mid == x / mid) { // sqr == x
                return mid;
            }

            else if(mid > x / mid) { // sqr > x
                right = mid - 1;
            }

            else {
                res = mid;
                left = mid + 1;
            }
        }

        return res;
    }
};