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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        ListNode* temp = head;
        int remain = 0;
        
        while(temp){
            remain++;
            temp = temp -> next;
        }

        if(remain >= k){
            int count = 0;
            while(curr && count < k){
                count++;
                forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
            }

            if(forward != NULL){
                head -> next = reverseKGroup(forward, k);
            }
        }
        else{
            return head;
        }

        // cout << prev -> val << " ";
        return prev;
    }
};