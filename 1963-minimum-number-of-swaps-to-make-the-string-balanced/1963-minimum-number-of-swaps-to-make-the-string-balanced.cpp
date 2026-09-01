class Solution {
public:
    int minSwaps(string s) {
  // Approach :- Greedy / Stack (Parenthesis) 
  // Time :- O(N)
  // Space :- O(1)
     
        int imbalance = 0;

        for(char c : s) {

            if(c == '[') {
                imbalance++;
            }

            else {
                if(imbalance > 0) {
                    imbalance--;
                }
            }
        }

        return (imbalance + 1) / 2;
    }
};