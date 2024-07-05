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
    void solve(vector<int> &arr, ListNode* &head){
        ListNode* curr = head -> next;
        ListNode* prev = head;
        int ind = 2;
        while(curr -> next){
            if(((prev -> val < curr -> val) && (curr -> val > curr -> next -> val)) || 
            ((prev -> val > curr -> val) && (curr -> val < curr -> next -> val))){
                arr.push_back(ind);
            }
            ind++;
            prev = curr;
            curr = curr -> next;
        }
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        solve(arr, head);
        int n = arr.size();
        int i = 1, min_diff = INT_MAX;
        if(arr.size() < 2){
            return {-1, -1};
        }
        else{
            while(i < n){
                min_diff = min(min_diff, arr[i] - arr[i-1]);
                i++;
            }
            int maxi = arr[arr.size()-1] - arr[0];
            return {min_diff, maxi};
        }
    }
};