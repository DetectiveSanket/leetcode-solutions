class Solution {
public:
    string removeStars(string s) {

  // Approach :-
  // Time :- O(N)
  // Space :- O(1)

        string str = "";

        for(auto c : s) {

            if(c == '*' ) {
                str.pop_back();
            }
            else {
                str.push_back(c);
            }
        }

        cout << "str:" << str << endl;
        return str;
    }
};