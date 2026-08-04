class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        int n = arr.size();

        unordered_map<int , int> mp;
        for(auto i : arr) {
            mp[i]++;
        }

        set<int> s;

        for(auto &[i , j]: mp) {
            // cout << i << " " << j << endl;

            if(s.find(j) != s.end()) {
                return false;
            }
            s.insert(j);
        }



        return true;
    }
};