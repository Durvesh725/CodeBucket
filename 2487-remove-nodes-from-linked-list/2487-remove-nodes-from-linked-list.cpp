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
class Solution {\
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
                
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* revHead1 = reverse(head);
        ListNode* revHead2 = revHead1;
        ListNode* prev = revHead1;
        ListNode* forward = revHead1 -> next;
        int maxi = prev -> val;
        while(forward){
            if(forward -> val >= prev -> val){
                maxi = forward -> val;
                prev = forward;
                forward = prev -> next;
            }
            else{
                prev -> next = forward -> next;
                forward = prev -> next;
            }
        }
        
        revHead1 = reverse(revHead2);
        return revHead1;
    }
};