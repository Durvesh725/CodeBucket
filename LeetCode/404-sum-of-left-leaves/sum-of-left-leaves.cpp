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
private:
    int inorder(TreeNode* root, int &ans, bool f){
        if(root == NULL)    return 0;
        inorder(root -> left, ans, 1);
        if(f && root -> left == NULL && root -> right == NULL)
            ans += root -> val;
        inorder(root -> right, ans, 0);

        return ans;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        bool f = 0;
        if(root -> left == NULL && root -> right == NULL)
            return ans;

        inorder(root, ans, f);
        return ans;
    }
};