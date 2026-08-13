class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
/* 
        // Brust forst approch
        vector<int> ans;
        int n = 1;
        int p = 0;

        while(ans.size() < k && arr.size() > p) {

            if(n != arr[p]) {
                ans.push_back(n);
                n++;
            }
            else {
                n++;
                p++;
            }
        }

        int remian = k - ans.size();
        int last = arr.back();

        while(remian > 0) {
            last += 1;
            ans.push_back(last);
            remian--;
        }

        return ans.back(); 
        
*/

// ------------------------------------ //

/* 
    // Linera approach (little better)
        vector<int> ans;
        int n = 1;
        int p = 0;

        while(ans.size() < k) {

            if(p < arr.size() && arr[p] == n) {
                p++;
            }
            else {
                ans.push_back(n);
            }
            n++;
        }

        return ans.back();
*/

// ----------------------------------//

  // Approach :- Binary search
  // Time :- O(log n)
  // Space :- O(1);

        int left = 0;
        int right = arr.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(arr[mid] - (mid + 1) < k) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }

        }

        return left + k;
    }
};