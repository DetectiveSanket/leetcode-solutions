class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

  // Approach :- Hashing
  // Time :- O(N);
  // Space :- O(N) 
  
        unordered_set<string> ban(banned.begin() , banned.end());
        unordered_map<string, int> mp;

        // converting paragraph string into lowercase and remove punctuation into space
        for(char &c : paragraph) {
            if(isalpha(c)) {
                c = tolower(c);
            }
            else {
                c = ' ';
            }
        }

        stringstream ss(paragraph);
        string word;
        string result;
        int maxC = 0;

        while(ss >> word) {
            if(ban.count(word)) continue;

            int freq = ++mp[word];
            if(freq > maxC) {
                maxC = freq;
                result = word;
            }
        }
        return result;
    }
};