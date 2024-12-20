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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int currlvl = 0;

        while(!q.empty()){
            int sz = q.size();
            vector<TreeNode*> levels;

            while(sz){
                TreeNode* node = q.front();
                q.pop();
                levels.push_back(node);

                if(node -> left)
                    q.push(node -> left);
                if(node -> right)
                    q.push(node -> right);

                sz--;
            }

            if(currlvl & 1){
                int n = levels.size();
                int l = 0, r = n-1;
                while(l < r){
                    swap(levels[l]->val, levels[r]->val);
                    l++, r--;
                }
            }

            currlvl++;
        }

        return root;
    }
};