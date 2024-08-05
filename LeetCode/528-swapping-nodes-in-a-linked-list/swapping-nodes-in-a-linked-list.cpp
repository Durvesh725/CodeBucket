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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp = temp -> next;
        }

        int cnt = 1;
        while(cnt < k){
            p1 = p1 -> next;
            cnt++;
        }

        cnt = 1;
        while(cnt < len - k + 1){
            p2 = p2 -> next;
            cnt++;
        }

        swap(p2 -> val, p1 -> val);

        return head;
    }
};