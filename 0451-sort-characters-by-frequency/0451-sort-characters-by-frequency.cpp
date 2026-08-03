class Solution {
public:
    string frequencySort(string s) {
        
  // Approach :- Hashing & Sorting
  // Time :- O(N + K log K)  [or O(N) since unique characters K is bounded]
  // Space :- O(1) auxiliary [since unique characters K <= 128]

        int n = s.length();
        string str = "";

        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        vector<pair<int, char>> vec;
        for (auto& pair : freqMap) {
            vec.push_back({pair.second, pair.first});
        }

        sort(vec.rbegin(), vec.rend());

        for (auto& p : vec) {
            int frequency = p.first;
            char ch = p.second;
            str.append(frequency, ch);
        }

        return str;
    }
};

