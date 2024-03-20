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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        int cnt = a-1;
        while(cnt){
            temp = temp -> next;
            cnt--;
        }

        ListNode* temp2 = temp -> next;
        cnt = b-a;
        while(cnt){
            temp2 = temp2 -> next;
            cnt--;
        }

        ListNode* endjoin = temp2 -> next;

        ListNode* tail = list2;
        while(tail -> next){
            tail = tail -> next;
        }
        
        temp -> next = list2;
        tail -> next = endjoin;

        return list1;
    }
};