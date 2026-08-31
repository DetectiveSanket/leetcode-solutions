class Solution {
public:
    int minInsertions(string s) {

  // Approach :- Stack , string
  // Time :- O(N)
  // Space :- O(1)

        int insertion = 0;
        int open_count = 0;

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {
                open_count++;
            }
            else {
                if(i + 1 < s.length() && s[i + 1] == ')') {
                    if(open_count > 0) {
                        open_count--;
                    }
                    else {
                        insertion++;
                    }
                    i++;
                }

                else {
                    if(open_count == 0) {
                        insertion += 2;
                    }
                    else {
                        insertion++;
                        open_count--;
                    }
                }
            }
        }

        if(open_count > 0) {
            insertion += open_count * 2;
        }

        return insertion;
    }
};