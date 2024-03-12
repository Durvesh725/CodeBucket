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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        unordered_map<int, ListNode*> um;
        um[0] = dummy;
        int ps = 0;

        while(head != NULL){
            ps += head -> val;
            //main logic
            if(um.find(ps) != um.end()){
                ListNode* start = um[ps];
                //need to calculate ps again as we
                int prefixSum = ps;
                ListNode* temp = start;
                //go through range
                while(temp -> next != head){
                    temp = temp -> next;
                    prefixSum += temp -> val;
                    um.erase(prefixSum);
                }
                start -> next = head -> next;
            }
            else{
                um[ps] = head;
            }
            head = head -> next;
        }
        ListNode* newHead = dummy -> next;
        delete(dummy);
        return newHead;
    }
};