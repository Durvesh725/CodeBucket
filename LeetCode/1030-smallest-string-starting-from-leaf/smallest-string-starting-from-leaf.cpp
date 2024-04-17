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
    void find(TreeNode* root, string s, string &ans){
        if(root == NULL){
            reverse(s.begin(), s.end());
            if(s < ans)
                ans = s;
            return;
        }

        char ch = 'a' + root -> val;
        if(root->left && root->right) {
            find(root -> left, s + ch, ans);
            find(root -> right, s + ch, ans);
        } 
        else if(root->left) {
            find(root -> left, s + ch, ans);
        } 
        else if(root->right) {
            find(root -> right, s + ch, ans);
        } 
        else {
            find(NULL, s + ch, ans); 
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        find(root, "", ans);
        return ans;
    }
};
