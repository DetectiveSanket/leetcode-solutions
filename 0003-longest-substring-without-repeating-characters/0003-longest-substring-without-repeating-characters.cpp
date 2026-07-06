class Solution {
public:
    int lengthOfLongestSubstring(string s) {

  // T: O(n);
  // S: O(N);      
        int n = s.length();
        int ans = 0;
        int left = 0;
        int right = 0;
        // unordered_map<char , int > seen;

        // Use a fixed-size array of 128 elements initialized to 0
        // This gives us strict O(1) space complexity and faster lookups
        vector<int> seen(128, 0);


        while (right < n) {
            char ch = s[right];
            seen[ch]++; 

            while(seen[ch] > 1) {
                seen[s[left]]--;
                left++;
            }

            ans = max(ans , right - left + 1);

            right++;
        }

        return ans;
    }
};

