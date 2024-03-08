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
    ListNode* getNewTail(ListNode* head, int k){
        int cnt = 1;
        ListNode* temp = head;
        while(temp){
            if(cnt == k)
                return temp;
            cnt++;
            temp = temp -> next;
        }
        return temp;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head;
            
        ListNode* temp = head;
        int len = 1;
        while(temp -> next){
            len++;
            temp = temp -> next;
        }

        //edge case: if the k is in multiple of len, the original list remains same even after rotation
        if(k % len == 0)    return head;

        //break k into smaller number
        k = k % len;

        //join end node to the org head
        temp -> next = head;

        ListNode* newTail = getNewTail(head, len - k);

        //update head
        head = newTail -> next;
        newTail -> next = NULL;

        return head;
    }
};