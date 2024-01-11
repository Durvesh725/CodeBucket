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
    int dfs(TreeNode* root, int maxVal, int minVal){
        if(root == NULL)
            return abs(maxVal - minVal);
        
        maxVal = max(maxVal, root -> val);
        minVal = min(minVal, root -> val);
        int leftDiff = dfs(root -> left, maxVal, minVal);
        int rightDiff = dfs(root -> right, maxVal, minVal);
        
        return max(leftDiff, rightDiff);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL)    
            return 0;
        return dfs(root, root -> val, root -> val);    
    }
};