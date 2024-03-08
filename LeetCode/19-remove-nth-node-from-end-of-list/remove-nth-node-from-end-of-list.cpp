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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp -> next;
        }

        //check if the node requested to be deleted is a head Node
        if(cnt == n){
            ListNode* newHead = head -> next;
            delete(head);
            return newHead;
        }

        //
        int res = cnt - n;
        temp = head;
        while(temp){
            res--;
            if(res == 0)
                break;
            temp = temp -> next;
        }

        ListNode* todelete = temp -> next;
        temp -> next = temp -> next -> next;
        delete(todelete);

        return head;
    }
};