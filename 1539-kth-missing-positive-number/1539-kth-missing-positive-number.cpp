class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
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

        cout << "size : " << ans.size() << endl;
        for(auto i : ans) {
            cout << i << " ";
        }

        int remian = k - ans.size();
        int last = arr.back();

        while(remian > 0) {
            last += 1;
            ans.push_back(last);
            remian--;
        }

        // return ans.empty() ? 6 : ans.back();
        return ans.back();
    }
};