class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

  // Approach :- Hashing
  // Time :- O(N)
  // Space :- O(N)      
        unordered_map<char , int> mp;

        for(auto c : stones) {
            mp[c]++;
        }

        int res = 0;

        for(auto c : jewels) {
            auto it = mp.find(c);

            if(it != mp.end()) { // its present
                res += it -> second;
            }

            // alternative
            // if(mp.count(c)) {
            //     res += mp[c];
            // }
        }

        return res;
    }
};