class Solution {
public:
    bool isAnagram(string s, string t) {

    // Approach:- Hashing
    // T: O(N);
    // S: O(N);   
     
        unordered_map<char , int> seen;
        if(s.length() != t.length()) {
            return false;
        }

        for(int i = 0; i < s.length(); i++) {
            seen[s[i]]++;
        }

        for(int i = 0; i < t.length(); i++) {
            
            char ch = t[i];
            if(seen.find(ch) != seen.end() && seen[ch] > 0) {
                seen[ch]--;
            }

            else {
                return false;
            }
        }

        return true;

// -------------------------------------------------------------------//

    // Simplest solution 😂😂😂😁
        // sort(s.begin() , s.end());
        // sort(t.begin() , t.end());

        // return s == t;
    }
};