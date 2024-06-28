/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rootToNode(TreeNode* root, vector<TreeNode*> &path, TreeNode* x){
        if(root == NULL)
            return false;

        path.push_back(root);
        if(root == x)
            return true;

        if(rootToNode(root -> left, path, x) || rootToNode(root -> right, path, x)){
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        rootToNode(root, path1, p);
        rootToNode(root, path2, q);

        int n = path1.size();
        int m = path2.size();
        int i = 0;
        TreeNode* lca = NULL;
        for(i = 0; i < min(n, m); i++){
            if(path1[i] != path2[i]){
                lca = path1[i-1];
                return lca;
            }
        }

        lca = path1[i-1];
        return lca;
    }
};