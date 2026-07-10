#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN

class Solution {
public:
    int myAtoi(string s) {

   // T:- O(N);
   // S:- O(1);

        int n = s.length();
        int i = 0;

        // Check for whiteSpace
        while (i < n && s[i] == ' ') { // isspace(s[i]);
            i++;
        }

        // If all char in string are whiteSpace
        if(i == n) {
            return 0;
        }

        // Handle sign
        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+') ) {
            if(s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Iterate on remaining string
        long long result = 0;
        while(i < n && isdigit(s[i])) {

            int digit = s[i] - '0';
            result = result * 10 + digit;

            if(result * sign > INT_MAX) return INT_MAX;
            if(result * sign < INT_MIN) return INT_MIN;

            i++;
        }

        return static_cast<int> (result * sign);
    }
};