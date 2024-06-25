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
    void solve(TreeNode *root1, TreeNode* root2, bool &isSymmetricb){
        if(root1 == NULL && root2 == NULL)
            return;

        if(root1 == NULL || root2 == NULL || root1 -> val != root2 -> val){
            isSymmetricb = false;
            return;
        }

        solve(root1 -> left, root2 -> right, isSymmetricb);
        // cout << root1 -> val << " " << root2 -> val << endl;
        solve(root1 -> right, root2 -> left, isSymmetricb);
    }

    bool isSymmetric(TreeNode* root) {
        bool isSymmetricb = true;
        solve(root -> left, root -> right, isSymmetricb);
        return isSymmetricb;
    }
};