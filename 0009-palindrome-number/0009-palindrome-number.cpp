class Solution {
public:
    bool isPalindrome(int x) {

    // T: O(N);
    // S: O(1);

        int digit = x;
        long long ans = 0;
        while (digit != 0) {
            int mod = digit % 10;
            ans = ans * 10 + mod;
            digit /= 10;
        }     

        cout << "ans is " << ans << endl;

        if(abs(ans) == x) {
            return true;
        }

        return false;

    }
};