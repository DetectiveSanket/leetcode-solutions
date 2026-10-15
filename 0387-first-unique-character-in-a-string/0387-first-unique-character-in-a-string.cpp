class Solution {
public:
    int firstUniqChar(string s) {

  // Approach :- Hash map / normalized key
  // Time :- O(N)
  // Space :- O(N*M)
        
        unordered_map<char , pair<int, int>> seen;
        // <char , <index , count> > seen;

        for(int i = 0; i < s.length(); i++) {
            if(seen.find(s[i]) == seen.end()) {
                seen[s[i]] = {i , 1};
            }
            else {
                seen[s[i]].second++;
            }
        }

        int ans = -1;

        for(const auto &[ch, data]: seen) {
            auto [idx , count] = data;
            if(count == 1) {
                if(ans == -1 || idx < ans) {
                    ans = idx;
                }
            }
        }

        return ans;

    }
};