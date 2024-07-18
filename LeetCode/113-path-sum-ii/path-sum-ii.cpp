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
    void solve(TreeNode* root, vector<vector<int>> &res, vector<int> &temp, int targetSum){
        if(root == NULL)
            return;

        temp.push_back(root -> val);
        if(!root -> left && !root -> right && targetSum == root -> val){
            res.push_back(temp);
        }
        else{
            solve(root -> left, res, temp, targetSum - root -> val);
            solve(root -> right, res, temp, targetSum - root -> val);
        }
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(root, res, temp, targetSum);
        return res;
    }
};