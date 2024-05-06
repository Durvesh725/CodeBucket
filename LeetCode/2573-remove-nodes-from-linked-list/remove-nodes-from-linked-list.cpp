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
        ListNode* rhead = reverse(head);
        ListNode* rheadorg = rhead;
        ListNode* prev = rhead;
        rhead = rhead -> next;
        int maxi = prev -> val;
        while(rhead){
            if(rhead -> val >= maxi){
                maxi = rhead -> val;
                prev = rhead;
                rhead = rhead -> next;
            }
            else{
                prev -> next = rhead -> next;
                rhead = prev -> next;
            }
        }

        head = reverse(rheadorg);
        return head;
    }
};