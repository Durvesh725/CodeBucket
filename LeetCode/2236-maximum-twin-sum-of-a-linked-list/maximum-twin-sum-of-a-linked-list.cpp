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
    int pairSum(ListNode* head) {
        ListNode* mid = getMid(head);
        ListNode* temp = mid -> next;
        ListNode* rev = reverse(temp);
        mid -> next = rev;

        ListNode* h1 = head;
        ListNode* h2 = mid -> next;
        int maxi = 0;

        while(h2){
            maxi = max(maxi, (h1 -> val + h2 -> val));
            h1 = h1 -> next;
            h2 = h2 -> next;
        }
        return maxi;
    }
};