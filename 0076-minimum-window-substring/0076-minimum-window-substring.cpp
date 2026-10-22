class Solution {
public:
    string minWindow(string s, string t) {
  // Approach :- sliding window 
  // Time :- O(N + M)
  // Space :-  O(N)

        if(s.length() < t.length()) return "";
        if(s.length() == t.length() && s == t) return s;

        unordered_map<char , int> seen;
        int left = 0;
        int start = 0;
        int min_ans = INT_MAX;
        int match = 0;

        for(auto c : t) {
            seen[c]++;
        }

        for(int right = 0; right < s.length(); right++) {

            char ch = s[right];

            // check if the current char is in the map
            if(seen.count(ch)) {
                seen[ch]--;

                if(seen[ch] >= 0) {
                    match++;
                }
            }

            while(match == t.length()) {
                int current_length = right - left + 1;
                if(current_length < min_ans) {
                    min_ans = current_length;
                    start = left;
                }

                char left_ch = s[left];
                if(seen.count(left_ch)) {
                    seen[left_ch]++;

                    if(seen[left_ch] > 0) {
                        match--;
                    }
                } 
                left++;
            }
        }

        return min_ans == INT_MAX ? "" : s.substr(start , min_ans);
    }
};