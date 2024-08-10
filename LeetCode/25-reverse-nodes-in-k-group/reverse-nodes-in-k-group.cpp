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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        ListNode* temp = head;
        int remain = 0;

        while(temp){
            remain++;
            temp = temp -> next;
        }

        int count = 0;
        if(remain >= k){
            while(curr && count < k){
                forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
                count++;
            }

            if(forward != NULL){
                head -> next = reverseKGroup(forward, k);
            }
        }
        else{
            return head;
        }

        return prev;
    }
};