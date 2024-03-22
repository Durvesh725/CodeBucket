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
    bool isPalindrome(ListNode* head) {
        if(head -> next  == NULL){
            return true;
        }

        ListNode* middle = getMid(head);
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);

        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        while(head2){
            if(head1 -> val != head2 -> val){
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return 1;
    }
};