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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int width = INT_MIN;
        while(!q.empty()){
            int min_ind = q.front().second;
            int size = q.size();
            int left = 0, right = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                long long curr_ind = q.front().second - min_ind;
                q.pop();

                if(i == 0)
                    left = curr_ind;
                if(i == size - 1)
                    right = curr_ind;

                if(node -> left)    q.push({node -> left, 2 * curr_ind + 1});
                if(node -> right)   q.push({node -> right, 2 * curr_ind + 2});
            }
            width = max(width, right - left + 1);
        }
        return width;
    }
};