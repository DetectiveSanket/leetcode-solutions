class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // char c = strs[0][0];

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