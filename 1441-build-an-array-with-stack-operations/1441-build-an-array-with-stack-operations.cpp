class Solution {
public:

  // Approach :- basic Stack
  // Time :- O(N)
  // Space :- O(1)

    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int targetIdx = 0;

        for(int i = 1; i <= n; i++) {

            // Rule 1:- alwasy push the incoming element
            ans.push_back("Push");

            if(i == target[targetIdx]) {
                targetIdx++;
            }
            else { // Rule 2:- if it does not match , discard it immediately
            ans.push_back("Pop");
            }

            // Rule 3:- stop as soon as all element of target have been matched
            if(targetIdx == target.size()) {
                break;
            }

        }

        return ans;
    }
};