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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
            return {};

        queue<TreeNode*> q;
        vector<int> ans;

        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int maxi = INT_MIN;

            while(sz){
                TreeNode* curr = q.front();
                q.pop();

                maxi = max(maxi, curr -> val);
                
                if(curr -> left)
                    q.push(curr -> left);
                if(curr -> right)
                    q.push(curr -> right);

                sz--;
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};