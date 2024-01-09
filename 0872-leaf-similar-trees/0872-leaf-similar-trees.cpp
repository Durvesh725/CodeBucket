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
    void inorder(TreeNode* root, vector<int> &temp){
        if(root == NULL)
            return;
            
        inorder(root -> left, temp);
        if(root -> left == NULL && root -> right == NULL){
            temp.push_back(root -> val);   
        }
        inorder(root -> right, temp);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        inorder(root1, t1);
        inorder(root2, t2);
        if(t1 == t2)
            return true;
        return false;
    }
};