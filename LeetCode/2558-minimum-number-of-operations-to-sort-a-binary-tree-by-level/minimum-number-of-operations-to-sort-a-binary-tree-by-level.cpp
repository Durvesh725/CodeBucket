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
    int check(vector<int> &arr){
        int swaps = 0;
        int n = arr.size();
        vector<int> target = arr;
        sort(target.begin(), target.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != target[i]) {
                swaps++;

                int curPos = pos[target[i]];
                pos[arr[i]] = curPos;
                swap(arr[curPos], arr[i]);
            }
        }
        return swaps;
    }
    

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int op = 0;

        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;

            while(sz){
                TreeNode* currNode = q.front();
                temp.push_back(currNode -> val);
                q.pop();

                if(currNode -> left)
                    q.push(currNode -> left);
                if(currNode -> right){
                    q.push(currNode -> right);
                }
                sz--;
            }

            op += check(temp);
        }

        return op;
    }
};