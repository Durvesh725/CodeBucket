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
    void treeToGraph(TreeNode* root, vector<int> adj[]){
        if(root == NULL)
            return;
        
        if(root -> left){
            adj[root -> val].push_back(root -> left -> val);
            //because we need parent too
            adj[root -> left -> val].push_back(root -> val);
        }
        
        if(root -> right){
            adj[root -> val].push_back(root -> right -> val);
            adj[root -> right -> val].push_back(root -> val);
        }
        
        treeToGraph(root -> left, adj);
        treeToGraph(root -> right, adj);
    }
    
    int bfs(vector<int> &vis, int start, vector<int> adj[]){
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        vis[start] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push({it, time+1});
                    vis[it] = 1;
                }
            }
            ans = max(ans, time);
        }
        return ans;
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        //convert tree to graph
        vector<int> adj[100001];
        vector<int> vis(100001);
        
        //convert tree to graph
        treeToGraph(root, adj);
        
        //perform bfs
        return bfs(vis, start, adj);
    }
};