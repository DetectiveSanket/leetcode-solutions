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
            // long long int sqr = (long long)mid * mid;

            if(mid == num / mid) { // num == sqr
                if(num % mid == 0 ) return true;

                left = mid + 1;
            }

            else if (mid > num / mid) { // num < sqr
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return false;
    }
};


// int left = 1;
// int right = num;
// while (left <= right) {
//     int mid = left + (right - left) / 2;
//     if (mid == num / mid) {
//         // Confirm there is no remainder frominteger division
//         if (num % mid == 0) return true;
        
//         // If there's a remainder, mid * mid isstrictly less than num
//         left = mid + 1;
//     } else if (mid > num / mid) {
//         right = mid - 1;
//     } else {
//         left = mid + 1;
//     }
// }