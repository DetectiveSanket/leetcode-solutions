class Solution {
public:
    int minimizedStringLength(string s) {

  // solution: 1 - unordered_set
        // unordered_set<char> unique_chars(s.begin(), s.end());
        // return unique_chars.size();

  // solution: 2 - Sorting [ T: O(nLogn) , S: O(1)]
        // sort(s.begin() , s.end());
        // int count = 1;
        // for(int i = 1; i < s.length(); i++) {
        //     if(s[i] != s[i - 1]) count++;
        // }

        // return count;

  // solution: 3 - Fixed-Size Frequency Array / Vector - [T: O(N), S: O(1)];   
        // vector<bool> seen(26 , false);
        // int count = 0;
        // for(char c : s) {
        //     if(!seen[c - 'a']) {
        //         seen[c - 'a'] = true;
        //         count++;
        //     }
        // }
        // return count;

  // solution: 4 - Stack - [T: O(N), S: O(1)];    
        sort(s.begin() , s.end());
        stack<char> st;

        for(char c : s) {
            if(st.empty() || st.top() != c) {
                st.push(c);
            }
        }
        return st.size();
    }
};