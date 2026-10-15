class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
  // Approach :- Hash map / normalized key
  // Time :- O(N)
  // Space :- O(N)     
        unordered_map<string , vector<string>> seen;

        for(auto s : strs) {

            string copy = s;
            sort(copy.begin() , copy.end());

            seen[copy].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto const &[key , pair] : seen) {
            ans.push_back(pair);
        }

        return ans;

    }
};