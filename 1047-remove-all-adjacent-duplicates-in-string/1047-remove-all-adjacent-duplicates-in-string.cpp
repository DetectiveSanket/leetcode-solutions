class Solution {
public:
    string removeDuplicates(string s) {

  // Approach :- Stack
  // Time :- O(N);
  // Space :- O(1);

        string str = "";

        for(auto c : s) {
            if(!str.empty() && c == str.back()) {
                str.pop_back();
            }
            else {
                str.push_back(c);
            }
        }

        return str;


        // for(int i = 0; i < s.length() ; i++) {
        //     char curr = s[i];

        //    if(!str.empty() && curr == str.back()) {
        //         str.pop_back();
        //     }

        //     else {
        //         str.push_back(curr);
        //     }
        // }

        // return str;
    }
};