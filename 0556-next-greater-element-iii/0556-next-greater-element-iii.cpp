class Solution {
public:
    int nextGreaterElement(int n) {
        
        string s = to_string(n);
        int start = -1; 

        // 1. Find the first dip from the right
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                start = i;
                break; 
            }
        }

        // If no dip is found, it's the largest possible permutation
        if (start == -1) {
            return -1;
        }

        // 2. Find the successor (first element from the right greater than s[start])
        int end = -1;
        for (int j = s.length() - 1; j > start; j--) {
            if (s[j] > s[start]) {
                end = j;
                break; // Stop once we find the successor
            }
        }

        // 3. Swap the pivot and successor
        swap(s[start], s[end]);

        // 4. Reverse the suffix AFTER the pivot
        reverse(s.begin() + start + 1, s.end());

        // 5. Check 32-bit integer limits and return
        long long res = stoll(s);
        if (res > INT_MAX) {
            return -1;
        }
        
        return res;




    }
};