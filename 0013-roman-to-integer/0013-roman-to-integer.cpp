class Solution {
public:
    int romanToInt(string s) {

    // Pattern: String Traversal (Right-to-Left)
    // Time Complexity: O(N) where N is the length of the string (or O(1) given constraint N <= 15)
    // Space Complexity: O(1)

        map<char , int> roman {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };

        int n = s.length();
        int total = 0;
        int preValue = 0;

        for(int i = n - 1; i >= 0; i--) {
            int currValue = roman[s[i]];

            if(currValue < preValue) {
                total -= currValue;
            }

            else {
                total += currValue;
            }

            preValue = currValue;
        }

        return total;
    }
};