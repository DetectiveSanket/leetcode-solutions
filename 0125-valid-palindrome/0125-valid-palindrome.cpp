class Solution {
public:
    bool isPalindrome(string s) {
  // Approach :- 2-pointer 
  // Time :- O(n) 
  // Space :- O(1)

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // first check for alphabet
            if(!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }

            else {
                if(tolower(s[left]) != tolower(s[right]) ) {
                    return false;
                }

                left++;
                right--;
            }
        }

        return true;
    }
};