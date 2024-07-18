class Solution {
public:
    void findLeaves(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>> &um, 
                    vector<TreeNode*> &leaves, vector<TreeNode*> &path){
        if (root == NULL)
            return;

        path.push_back(root); 
        if(root->left == NULL && root->right == NULL){ 
            um[root] = path; 
            leaves.push_back(root); 
        } 
        else{
            findLeaves(root->left, um, leaves, path); 
            findLeaves(root->right, um, leaves, path); 
        }
        path.pop_back(); 
    }

    int countPairs(TreeNode* root, int distance){
        unordered_map<TreeNode*, vector<TreeNode*>> um;
        vector<TreeNode*> leaves;
        vector<TreeNode*> path;
        int ans = 0;

        findLeaves(root, um, leaves, path); 
        
        int n = leaves.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                vector<TreeNode*> path_l1 = um[leaves[i]];
                vector<TreeNode*> path_l2 = um[leaves[j]];
                int k = 0;
                while(k < path_l1.size() && k < path_l2.size() && path_l1[k] == path_l2[k]){
                    k++; 
                }
                int dist = (path_l1.size() - k) + (path_l2.size() - k); 
                if(dist <= distance){
                    ans++;
                }
            }
        }

        return ans;
    }
};
