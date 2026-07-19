class Solution {
public:
    int firstUniqChar(string s) {

  // Approach :- Hashing
  // Time :- O(N);
  // Space :- O(N);    

        int n = s.length();

        // unordered_map<char , int> mp;
        // for(int i = 0; i < n; i++) {
        //     mp[s[i]]++;
        // }


        // for(int i = 0; i < n; i++) {
        //     char ch = s[i];
        //     if(mp.find(ch) != mp.end() && mp[ch] == 1) {
        //         return i;
        //     }
        // }
        
        // return -1;

// Approach :- Frequency Counting (using a fixed-size array)
// Time :- O(N);
// Space :- O(1);

        int count[26] = {0};

        for(char ch : s) {
            count[ch - 'a']++;
        }

        for(int i = 0; i < n; i++) {
            if(count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};