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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* newHead){
        ListNode* curr = newHead;
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
    void reorderList(ListNode* head) {
        ListNode* mid = getMid(head);
        mid -> next = reverse(mid -> next);

        ListNode* h1 = head;
        ListNode* h2 = mid -> next;
        mid -> next = NULL;

        while(h1 && h2){
            ListNode* f1 = h1 -> next;
            ListNode* f2 = h2 -> next;

            h1 -> next = h2;
            h2 -> next = f1;

            h1 = f1;
            h2 = f2;
        }
    }
};