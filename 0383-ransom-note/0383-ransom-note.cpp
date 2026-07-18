class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

  // Approach:- Hasing
  // Time :- O(N);
  // Space :- O(N);
        
        if(magazine.length() < ransomNote.length()) {
            return false;
        }

        unordered_map<char ,int> mp;
        for(int i = 0; i < magazine.length(); i++) {
            mp[magazine[i]]++;
        }

        for(int i = 0; i < ransomNote.length(); i++) {

            char ch = ransomNote[i];    
            if(mp.find(ch) != mp.end() && mp[ch] > 0) {
                mp[ch]--;
            }

            else {
                return false;
            }
        }

        return true;
    }
};