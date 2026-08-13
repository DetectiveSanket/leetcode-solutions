// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*  
    - To help you, LeetCode gives you a helper function/API:
        isBadVersion(version)
            - Returns true if version is bad.
            - Returns false if version is good.
 */
class Solution {
public:
    int firstBadVersion(int n) {

  // Approach :- Binary Search
  // Time :- O(log N)
  // Space :- O(1)

        int left = 1;
        int right = n;

        while(left < right) {

            int mid = left + (right - left) / 2;

            if(isBadVersion(mid)) { // true = bad
                right = mid;
            }
            else { // false = good
                left = mid + 1;
            }
        }

        return left;
    }
};