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
    void levelOrder(TreeNode* root, vector<int> &l){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            l.push_back(node -> val);

            if(node -> left)
                q.push(node -> left);
            if(node -> right)
                q.push(node -> right);
        }
    }

    TreeNode* constructBST(TreeNode* root, int data){
        if(root == NULL){
            TreeNode* root = new TreeNode(data);
            return root;
        }

        if (data <= root->val)
            root->left = constructBST(root->left, data);
        else
            root->right = constructBST(root->right, data);

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        vector<int> l;
        levelOrder(root, l);

        int index = 0;
        int n = l.size();
        for(int i = 0; i < n; i++){
            if(l[i] >= low && l[i] <= high)
                l[index++] = l[i];
        }    

        TreeNode* newRoot = NULL;
        cout << index << endl;
        for(int i = 0; i < index; i++)
            newRoot = constructBST(newRoot, l[i]);

        return newRoot;
    }
};