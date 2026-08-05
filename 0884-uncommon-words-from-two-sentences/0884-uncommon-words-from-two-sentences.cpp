#include <sstream>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
  
  // Approach :- Hashing
  // Time :- O(N+M)
  // Space :- O(O+M)   

       unordered_map<string , int> mp;

       stringstream ss(s1 + " " + s2); // join the s1 and s2 string in to ss with space
       string word;

        // count the freq of each word in the ss 
        while(ss >> word){
            mp[word]++;
        }

        vector<string> res;
        for(auto const&[word , val] : mp) {
            if(val == 1) {
                res.push_back(word);
            }
        }
        return res;
    }
};