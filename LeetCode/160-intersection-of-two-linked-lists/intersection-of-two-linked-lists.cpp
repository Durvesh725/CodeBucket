/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp -> next;
        }
        return len;
    }

    ListNode* findCollision(ListNode* headA, ListNode* headB, int d){
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(d){
            d--;
            temp2 = temp2 -> next;
        }

        while(temp1 && temp2){
            if(temp1 == temp2)
                return temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = getLength(headA);
        int l2 = getLength(headB);

        if(l1 < l2){
            return findCollision(headA, headB, l2-l1);
        }
        else{
            return findCollision(headB, headA, l1-l2);
        }

        return NULL;
    }
};