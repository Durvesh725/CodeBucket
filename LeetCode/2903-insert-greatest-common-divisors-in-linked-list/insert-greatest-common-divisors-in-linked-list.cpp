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
    int findGCD(int a, int b){
        while(a > 0 && b > 0){
            if(a > b){
                a = a % b;
            }
            else{
                b = b % a;
            }
        }

        if(a == 0)  return b;
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head -> next == NULL)
            return head;

        ListNode* p1 = head;
        ListNode* p2 = head -> next;
        ListNode* dummy = new ListNode(-1);
        ListNode* dhead = dummy;
        ListNode* temp = dhead;

        while(p2){
            temp -> next = p1;
            temp = p1;
            int val = findGCD(p1 -> val, p2 -> val);
            ListNode* gcd = new ListNode(val);
            temp -> next = gcd;
            temp = gcd;
            temp -> next = p2;

            p1 = p2;
            p2 = p2 -> next;
        }

        return dhead -> next;
    }
};