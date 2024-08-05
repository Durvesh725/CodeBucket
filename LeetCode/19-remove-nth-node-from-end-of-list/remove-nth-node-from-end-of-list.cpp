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
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp -> next;
        }

        int pos = len - n + 1;
        if(pos == 1){
            ListNode* temp = head;
            head = head -> next;
            delete temp;
        }
        else{
            ListNode* curr = head;
            int cnt = 1;
            while(cnt < pos - 1){
                curr = curr -> next;
                cnt++;
            }

            ListNode* todelete = curr -> next;
            curr -> next = curr -> next -> next;
            todelete -> next = NULL;
            delete todelete;
        }

        return head;
    }
};