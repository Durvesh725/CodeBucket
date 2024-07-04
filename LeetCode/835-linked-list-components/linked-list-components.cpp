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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> st;
        int c = 0;
        ListNode* curr = head;

        for(int &i: nums){
            st.insert(i);
        }

        while(curr){
            if(st.find((*curr).val) != st.end()){
                if(curr -> next){
                    if(st.find(curr -> next -> val) == st.end()){
                        c++;
                    }
                }
                else{
                    c++;
                }
            }
            curr = curr -> next;
        }

        return c;
    }
};