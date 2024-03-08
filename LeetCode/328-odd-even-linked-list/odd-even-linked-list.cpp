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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
            
        vector<int> a;

        //odd
        ListNode* temp = head;
        while(temp && temp -> next){
            a.push_back(temp -> val);
            temp = temp -> next -> next;
        }
        if(temp) a.push_back(temp -> val);

        temp = head -> next;
        while(temp && temp -> next){
            a.push_back(temp -> val);
            temp = temp -> next -> next;
        }
        if(temp) a.push_back(temp -> val);

        //replace
        temp = head;
        int i = 0;
        while(temp){
            temp -> val = a[i];
            i++;
            temp = temp -> next;
        }
        return head;
    }
};