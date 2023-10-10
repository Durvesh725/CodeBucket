/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp -> left){
                parent_track[temp -> left] = temp;
                q.push(temp -> left);
            }
            if(temp -> right){
                parent_track[temp -> right] = temp;
                q.push(temp -> right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //Step-1: Record all the parent pointers using BFS
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);
        
        //Step-2: Visit each node in all the directions till dist = k
        //visited map
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        
        int dist = 0;
        
        while(!q.empty()){
            int size = q.size();
            //IMP
            if(dist == k)   break;
            dist++;
            //traverse each time till the length of the queue
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                //direction-1
                if(curr -> left && !vis[curr -> left]){
                    q.push(curr -> left);
                    vis[curr -> left] = true;
                }
                
                //direction-2
                if(curr -> right && !vis[curr -> right]){
                    q.push(curr -> right);
                    vis[curr -> right] = true;
                }
                
                //check parent
                if(parent_track[curr] && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }
        
        //push result into vector
        vector<int> ans;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp -> val);
        }
        return ans;
    }
};