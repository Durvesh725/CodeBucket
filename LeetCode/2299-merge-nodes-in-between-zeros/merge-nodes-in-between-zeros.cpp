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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* curr = head -> next;
        int sum = 0;
        while(curr){
            sum = 0;
            while(curr -> val != 0){
                sum += curr -> val;
                curr = curr -> next;
            }

            ListNode* newNode = new ListNode(sum);
            temp -> next = newNode;
            temp = newNode;
            curr = curr -> next;
        }

        return dummy -> next;
    }
};