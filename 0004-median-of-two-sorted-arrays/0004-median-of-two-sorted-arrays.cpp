#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        vector<int> v;
        v.reserve(n + m);

        for(int i : nums1) {
            v.push_back(i);
        }

        for(auto i : nums2) {
            v.push_back(i);
        }

        sort(v.begin() , v.end());

        int size = v.size(); 


        //check the size is odd
        if(size % 2 == 1) { // size is odd
            return static_cast<double>(v[size / 2]);
        }

        else { // size is even
            int mid1 = v[size / 2 - 1];
            int mid2 = v[size / 2];
            return static_cast<double>(mid1 + mid2) / 2.0;
        }
    }
};