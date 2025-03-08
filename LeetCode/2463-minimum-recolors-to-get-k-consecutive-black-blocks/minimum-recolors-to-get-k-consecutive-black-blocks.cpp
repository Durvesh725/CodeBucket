class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        vector<int> pre(n);
        pre[0] = (blocks[0] == 'B') ? 1 : 0;

        for(int i = 1; i < n; i++){
            if(blocks[i] == 'B')
                pre[i] = pre[i-1] + 1;
            else
                pre[i] = pre[i-1];
        }
        
        int mini = INT_MAX;
        int i = 0;
        while(i <= n - k){
            int op = (i == 0) ? k - pre[i + k - 1] : k - (pre[i + k - 1] - pre[i-1]);
            mini = min(mini, op);
            i++;
        }

        return mini;
    }
};