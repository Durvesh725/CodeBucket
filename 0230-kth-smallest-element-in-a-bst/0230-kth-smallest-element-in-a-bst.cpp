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
    //app-2: Using counter
    int solve(TreeNode* root, int k, int &i){
        if(root == NULL){
            return -1;
        }
        //IMP
        //because we want to find kth smallest ele that will always exists to the left of the root
        //if we find that ele, we'll return it
        int left = solve(root -> left, k, i);
        if(left != -1)
            return left;
        i++;
        if(i == k)
            return root -> val;
        return solve(root -> right, k, i);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = solve(root, k, i);
        return ans;
    }
};