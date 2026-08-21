// Approach :- 1. Binary Search 
// Time :- O(2^N * log(min(coins) * k)), where N = coins.size() <= 15.
// Space :- O(1) auxiliary space.

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    long long countMultiples(long long target, const vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bit_count = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bit_count++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    if (current_lcm > target) break;
                }
            }

            if (current_lcm <= target) {
                if (bit_count % 2 == 1) {
                    total += target / current_lcm;
                } else {
                    total -= target / current_lcm;
                }
            }
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};