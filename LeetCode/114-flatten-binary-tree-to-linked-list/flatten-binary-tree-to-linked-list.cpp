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
    void solve(TreeNode* root, vector<TreeNode*> &list){
        if(root == NULL)
            return;
        
        list.push_back(root);
        solve(root -> left, list);
        solve(root -> right, list);
    }

    void flatten(TreeNode* root) {
        if(root == NULL)
            return;

        vector<TreeNode*> list;
        solve(root, list);

        int n = list.size();
        for(int i = 0; i < n-1; i++){
            list[i] -> left = NULL;
            list[i] -> right = list[i+1];
        }

        list[n-1] -> left = NULL;
        list[n-1] -> right = NULL;
    }
};