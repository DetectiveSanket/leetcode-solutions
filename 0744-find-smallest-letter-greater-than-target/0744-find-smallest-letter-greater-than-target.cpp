class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

  // Approach :- Binary Search
  // Time :- O(log N)
  // Space :- O(1)
  
        int left = 0;
        int right = letters.size() - 1;
        char ans = letters[0]; 

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                ans = letters[mid]; // Found a valid character, try to find a smaller one to the left
                right = mid - 1;
            } else {
                left = mid + 1; // Needs to be strictly greater than target, so move right
            }
        }

        return ans;
    }
};