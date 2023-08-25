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
//     int height(TreeNode* node){
//         //base case
//         if(node == NULL){
//             return 0;
//         }
        
//         int left = height(node -> left);
//         int right = height(node -> right);
        
//         int ans = max(left, right) + 1;
//         return ans;
//     }
    pair<int, int> isBalancedFast(TreeNode *root){
        if(root == NULL){
            pair<int, int> p = make_pair(true, 0);
            return p;
        }
        
        //calculate existence of left and right subtree along with its respective height
        pair<int, int> left = isBalancedFast(root -> left);
        pair<int, int> right = isBalancedFast(root -> right);
        
        //store ans
        bool leftans = left.first;
        bool rightans = right.first;
        
        //calculate absolute difference between the heights of left and right subtree
        bool diff = abs(left.second - right.second) <= 1;
        
        //create ans pair
        pair<bool, int> ans;
        //calculate and store height
        ans.second = max(left.second, right.second) + 1;
        
        if(leftans && rightans && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;    
    }
};