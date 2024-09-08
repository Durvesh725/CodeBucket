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
    int getLength(ListNode* head, int k){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp -> next;
        }

        return len;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        if(head == NULL){
            while(k){
                ans.push_back(NULL);
                k--;
            }
            return ans;
        }

        int length = getLength(head, k);
        int extra = length % k;

        ListNode* temp = head;
        ListNode* prev = NULL;
        int p = k;

        while(p){
            if(extra){
                int cnt = (length/k) + 1;
                ListNode* tempHead = temp;

                while(temp && cnt){
                    prev = temp;
                    temp = temp -> next;
                    cnt--;
                }

                prev -> next = NULL;
                ans.push_back(tempHead);
                extra--;
                p--;
            }
            else{
                int cnt = (length/k);
                ListNode* tempHead = temp;

                while(temp && cnt){
                    prev = temp;
                    temp = temp -> next;
                    cnt--;
                }

                prev -> next = NULL;
                ans.push_back(tempHead);
                p--;
            }
        }

        return ans;
    }
};