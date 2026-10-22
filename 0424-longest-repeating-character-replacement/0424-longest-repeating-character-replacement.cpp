class Solution {
public:
    int characterReplacement(string s, int k) {

  // Approach :- sliding window 
  // Time :- O(n) 
  // Space :- O(1) 
    //> Bad solution..

        // int n = s.length();
        // int ans = 0;

        // for(int i = 0; i < n - 1; i++) {
        //     char ch = s[i];
        //     int right = i + 1;
        //     while (k >= 0 && right < n) {
        //         if(s[right] != ch && k != 0) {
        //             k--;
        //         }
        //         else if (k == 0 && (right < n - 1 && ch != s[right + 1]) ) {
        //             ans = max(ans , right - i + 1  );
        //             break;
        //         }

        //         ans = max(ans , right - i + 1);
        //         right++;
        //     }
        // }
        // return ans;

  // Approach :- sliding window 
  // Time :- O(n) 
  // Space :- O(1) 
     
        vector<int> count(26 , 0);
        int left = 0;
        int max_length = 0;
        int max_count = 0;

        for(int right = 0; right < s.length(); right++) {

            // update the in count
            count[s[right] - 'A']++;

            // update the max_count
            max_count = max(max_count , count[s[right] - 'A']);

            // check size of k > so basically window is break here...
            while( (right - left + 1) - max_count > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // update the max_length(window count)
            max_length = max(max_length , right - left + 1);
        }

        return max_length;
    }
};