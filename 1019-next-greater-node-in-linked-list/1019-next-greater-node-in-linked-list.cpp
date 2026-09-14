/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

  // Approach :- monotonic stack 
  // Time :- O(N)
  // Space :- O(N)

        // int n = 0;
        // ListNode* temp = head;
        // while(temp != nullptr) {
        //     n++;
        //     temp = temp -> next;
        // }

        // stack<pair<int,int>> st;
        // vector<int> ans (n , 0);
        // temp = head;

        // int i = 0;
        // while(temp != nullptr) {

        //     while(!st.empty() && temp -> val > st.top().first) {
        //        int ind = st.top().second;
        //        ans[ind] = temp -> val;
        //        st.pop();
        //     }

        //     st.push({temp -> val , i});
        //     temp = temp -> next;
        //     i++;
        // }

        // return ans;

        //> convert the linkedList into vector
        ListNode *temp = head;
        vector<int> arr;
        while(temp != nullptr) {
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        
        stack<int> st;
        vector<int> ans(arr.size() , 0);
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[i] > arr[st.top()] ) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};