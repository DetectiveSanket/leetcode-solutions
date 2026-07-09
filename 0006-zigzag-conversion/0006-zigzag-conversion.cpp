

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) {
            return s;
        }

        vector<string> row(numRows , "");

        int currentRow = 0;
        bool goingDown = false;
        
        for(char c : s) {
            row[currentRow] += c;

            if(currentRow == 0 || currentRow == numRows - 1) {
                goingDown =  !goingDown;
            }

            if(goingDown) {
                currentRow++;
            }
            else {
                currentRow--;
            }
        }

        string res = "";
        for(const string &rows : row ) {
            res += rows;
        }

        return res;
    }
};