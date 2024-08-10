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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* ref_head = head;
        ListNode* curr = head;
        ListNode* tail = NULL;
        int group = 0;

        while(curr){
            group++;
            int len = 0;

            while(len < group && curr){
                len++;
                curr = curr -> next;
            }    

            ListNode* prev = NULL;
            ListNode* forward = NULL;
            curr = head;

            if(len % 2 == 0){
                while(len){
                    forward = curr -> next;
                    curr -> next = prev;
                    prev = curr;
                    curr = forward;
                    len--;
                }

                if(tail != NULL){
                    tail -> next = prev;
                }

                tail = head;
            }
            else{
                while(len){
                    prev = curr;
                    curr = curr -> next;
                    len--;
                }

                if(tail != NULL){
                    tail -> next = head;
                }

                tail = prev;
            }

            head = curr;
        }

        return ref_head;
    }
};