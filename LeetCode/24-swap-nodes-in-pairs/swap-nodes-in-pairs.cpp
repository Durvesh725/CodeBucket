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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = head;
        ListNode* prev = dummy;

        while(curr && curr -> next){
            prev -> next = curr -> next;
            curr -> next = curr -> next -> next;
            prev -> next -> next = curr;

            prev = curr;
            curr = curr -> next;
        }

        return dummy -> next;
    }
};