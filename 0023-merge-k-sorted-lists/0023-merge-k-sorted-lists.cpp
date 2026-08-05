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

 #include <queue>

class Solution {
public:

    struct campare {
        bool operator() (ListNode *a , ListNode *b) {
            return a -> val > b -> val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode * , vector<ListNode *> , campare> minHeap;

        // inset all the k linked list in minheap
        for(ListNode *list : lists) {
            if(list) {
                minHeap.push(list);
            }
        }

        // create one dummpy node
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while(!minHeap.empty()) {

            ListNode *topNode = minHeap.top();
            minHeap.pop(); 

            current -> next = topNode;
            current = current -> next;

            if(topNode -> next) {
                minHeap.push(topNode -> next);
            }
        }

        return dummy -> next;
    }
};