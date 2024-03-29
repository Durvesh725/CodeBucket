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
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        ListNode* temp = head;
        while(temp != NULL){
            if(s.find(temp) != s.end())   return true;
            s.insert(temp);
            temp = temp -> next;
        }
        return NULL;
    }
};