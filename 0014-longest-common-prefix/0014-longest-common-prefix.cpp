class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
// Pattern: Vertical Scanning
// Time Complexity: O(N * M) where N is number of strings, M is length of the first string
// Space Complexity: O(1) (excluding the output string)

        int n = strs[0].size();
        // cout << "size: " << n << endl;
        // cout << "size of v: " << strs.size() << endl;

        string str = "";

        for(int i = 0; i < n; i++) {
            char c = strs[0][i];
            // cout << "str i : " << c << endl; 

            for(int j = 1; j < strs.size(); j++) {

                // cout << "str : " << strs[j][i] << endl;
                if(c != strs[j][i]) {
                    return str;
                }
            }

            str += c;
        }

        return str;
    }
};
