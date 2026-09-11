class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;

        string currentExpr = "";
        backtrack(0, 0, 0, num, target, currentExpr, result);
        return result;
    }

private:
    void backtrack(int index, long long eval, long long prev, 
                   const string& num, long long target, 
                   string& expr, vector<string>& result) {
        if (index == num.length()) {
            if (eval == target) {
                result.push_back(expr);
            }
            return;
        }

        int originalLen = expr.length();
        long long currNum = 0;

        for (int i = index; i < num.length(); ++i) {
            // Numbers with leading zeros (e.g., "05") are invalid
            if (i > index && num[index] == '0') break;

            currNum = currNum * 10 + (num[i] - '0');
            string currStr = num.substr(index, i - index + 1);

            if (index == 0) {
                // First operand has no operator before it
                expr += currStr;
                backtrack(i + 1, currNum, currNum, num, target, expr, result);
                expr.resize(originalLen);
            } else {
                // Addition (+)
                expr += "+" + currStr;
                backtrack(i + 1, eval + currNum, currNum, num, target, expr, result);
                expr.resize(originalLen);

                // Subtraction (-)
                expr += "-" + currStr;
                backtrack(i + 1, eval - currNum, -currNum, num, target, expr, result);
                expr.resize(originalLen);

                // Multiplication (*)
                expr += "*" + currStr;
                backtrack(i + 1, eval - prev + (prev * currNum), prev * currNum, num, target, expr, result);
                expr.resize(originalLen);
            }
        }
    }
};