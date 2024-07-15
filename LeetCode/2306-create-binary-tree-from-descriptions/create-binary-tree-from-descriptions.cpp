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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> um;
        set<int> child;

        for(vector<int> &arr: descriptions){
            int p = arr[0], c = arr[1], isLeft = arr[2];
            child.insert(c);

            if(um.find(p) == um.end()){
                um[p] = new TreeNode(p);
            }
            if(um.find(c) == um.end()){
                um[c] = new TreeNode(c);
            }

            if(isLeft){
                um[p] -> left = um[c];
            }
            else{
                um[p] -> right = um[c];
            }
        }

        
        // for(auto it: um){
        //     cout << it.first << " " << it.second << endl;
        // }

        int root = -1;
        for(vector<int> &arr: descriptions){
            if(child.find(arr[0]) == child.end()){
                root = arr[0];
                break;
            }
        }

        return um[root];
    }
};