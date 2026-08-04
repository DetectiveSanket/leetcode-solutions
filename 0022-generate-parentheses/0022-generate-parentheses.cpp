class Solution {

  // Approach :- Backtracking (Depth-First Search)
  // Time :- O(4^n / sqrt(n))
  // Space :- O(N)

private:

    void backtracking(vector<string> &result , string &current , int open , int close , int n ) {

        //base case: if my current string length is equal to 2 * n;
        if(current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // add open brackets
        if(open < n) {
            current.push_back('(');
            backtracking(result , current , open + 1 , close , n);
            current.pop_back(); // backtracking
        }

        if(close < open) {
            current.push_back(')');
            backtracking(result , current , open , close + 1 , n);
            current.pop_back(); // backtracking
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtracking(result , current , 0 , 0 , n);
        return result;
    }
};