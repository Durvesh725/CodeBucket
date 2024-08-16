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
    void solve(TreeNode* root, vector<int> &inorder){
        if(root == NULL)
            return;
        solve(root -> left, inorder);
        inorder.push_back(root -> val);
        solve(root -> right, inorder);
    }

    int findLowerBound(vector<int> &arr, int n){
        int lb = -1;
        int s = arr.size();
        int l = 0, r = s - 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(arr[mid] <= n){
                lb = arr[mid];
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return lb;
    }

    int findUpperBound(vector<int> &arr, int n){
        int ub = -1;
        int s = arr.size();
        int l = 0, r = s - 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(arr[mid] >= n){
                ub = arr[mid];
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ub;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> inorder;
        solve(root, inorder);
        for(int n: queries){
            int floor = findLowerBound(inorder, n);
            int ceil = findUpperBound(inorder, n);

            ans.push_back({floor, ceil});
        }
        return ans;
    }
};