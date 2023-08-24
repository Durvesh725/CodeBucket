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
    void inOrder(TreeNode* root, int &cnt){
    if(root == NULL)    return;

    //left direction
    inOrder(root -> left, cnt);
    
    cnt++;
        
    //right direction
    inOrder(root -> right, cnt);
}
    
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;
        inOrder(root, cnt);
        return cnt;
    }
};