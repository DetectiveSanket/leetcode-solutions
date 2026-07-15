class Solution {
public:
    int maxArea(vector<int>& height) {
  // Pattern:- Two Pointer Approach 
  // T :- O(N);
  // S :- O(1);      
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int ans = INT_MIN;

        while(left <= right) {
            int len = right - left;
            int hei = min(height[left] , height[right]);
            int area = len * hei;

            ans = max(area , ans);

            if(height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};