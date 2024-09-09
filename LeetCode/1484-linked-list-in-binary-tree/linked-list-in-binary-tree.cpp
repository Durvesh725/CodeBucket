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
    bool dfs(ListNode* head, ListNode* curr, TreeNode* root){
        if(curr == NULL)
            return true;
        
        if(root == NULL)
            return false;

        if(root -> val == curr -> val)
            curr = curr -> next;
        else if(root -> val == head -> val)
            head = head -> next;
        else
            curr = head;

        return dfs(head, curr, root -> left) || dfs(head, curr, root -> right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, head, root);
    }
};