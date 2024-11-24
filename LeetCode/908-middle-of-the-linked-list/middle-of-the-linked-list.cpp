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
    ListNode* middleNode(ListNode* head) {
        int cntNodes = 0;
        ListNode* temp = head;

        while(temp != NULL){
            cntNodes++;
            temp = temp -> next;
        }

        int mid = 0;
        mid = cntNodes / 2;

        int cnt = 0;
        temp = head;
        while(temp && cnt != mid){
            cnt++;
            temp = temp -> next;
        }

        return temp;
    }
};