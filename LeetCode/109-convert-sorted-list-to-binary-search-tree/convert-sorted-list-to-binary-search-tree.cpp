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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* getMidPrev(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow_prev = slow;
            slow = slow->next;
        }

        return slow_prev;
    }

    TreeNode* solve(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode* mid_prev = getMidPrev(head);
        if (mid_prev == nullptr)  
            return new TreeNode(head->val);

        ListNode* mid = mid_prev->next;
        mid_prev->next = nullptr;  

        TreeNode* root = new TreeNode(mid->val);
        root->left = solve(head);          
        root->right = solve(mid->next);    

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr)
            return new TreeNode(head->val);

        return solve(head);
    }
};