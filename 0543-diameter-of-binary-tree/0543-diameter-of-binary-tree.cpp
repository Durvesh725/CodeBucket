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
    pair<int, int> fastDiameter(TreeNode* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        //now instead of calling height function seperately, 
        //we'll calculate it along with diameter call
        pair<int, int> left = fastDiameter(root -> left);
        pair<int, int> right = fastDiameter(root -> right);
        
        //pair.first will store the diameter of the tree 
        //pair.second will store the height of the tree
        int op1 = left.first;
        int op2 = right.first;
        //calculate height
        int op3 = left.second + right.second;
        
        //store ans
        pair<int, int> ans;
        //store max diameter
        ans.first = max(op1, max(op2, op3));
        //store max height
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        return fastDiameter(root).first;
    }
};