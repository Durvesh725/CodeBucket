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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int sr = 0;
        int sc = 0;
        int er = m-1;
        int ec = n-1;

        //start row
        while(head){
            for(int i = sc; i <= ec && head; i++){
                ans[sr][i] = head -> val;
                head = head -> next;
            }
            sr++;

            //last col
            for(int i = sr; i <= er && head; i++){
                ans[i][ec] = head -> val;
                head = head -> next;
            }
            ec--;

            //last row
            for(int i = ec; i >= sc && head; i--){
                ans[er][i] = head -> val;
                head = head -> next;
            }
            er--;

            //first col
            for(int i = er; i >= sr && head; i--){
                ans[i][sc] = head -> val;
                head = head -> next;
            }
            sc++;
        }
        
        return ans;
    }
};