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
    ListNode* merge(ListNode* t1, ListNode* t2){
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        
        while(t1 != NULL && t2 != NULL){
            if(t1 -> val <= t2 -> val){
                res -> next = t1;
                res = t1;
                t1 = t1 -> next;
            }
            else{
                res -> next = t2;
                res = t2;
                t2 = t2 -> next;
            }
        }
        
        if(t1){
            res -> next = t1;
        }
        else{
            res -> next = t2;
        }
        
        return dummy -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
            
        ListNode* head = lists[0];

        for(int i = 1; i < n; i++){
            head = merge(head, lists[i]);
        }

        return head;
    }
};