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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // need to maintain lvl too because top to bottom it must be sorted
        // {Node, {vertical, level}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        // <vertical, <level, (nodes val.....)>> - all ordered values will be maintained
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int ver = q.front().second.first;
            int lvl = q.front().second.second;
            q.pop();

            mp[ver][lvl].insert(node -> val);

            if(node -> left){
                q.push({node -> left, {ver - 1, lvl + 1}});
            }
            if(node -> right){
                q.push({node -> right, {ver + 1, lvl + 1}});
            }
        }

        vector<vector<int>> ans;
        for(auto it: mp){
            vector<int> col;
            for(auto ver_nodes: it.second){
                col.insert(col.end(), ver_nodes.second.begin(), ver_nodes.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

//same concept of top/bottom view of BT