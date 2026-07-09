class Solution {
public:
    int reverse(int x) {

        long long revN = 0;
        int digit = x;

        while(digit != 0) {
            int mod = digit % 10;
            revN = revN * 10 + mod;
            digit /= 10;
        }

        // checking for 32 bit...
        if(revN > INT_MAX || revN < INT_MIN) {
            return 0;
        }

        return static_cast<int> (revN);

    }
};