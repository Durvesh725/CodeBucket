class Solution {
public:
    bool isBalanced(string num) {
        int oc = 0, ec = 0;
        int n = num.size();
        
        for(int i = 0; i < n; i++){
            if(i&1)
                oc += num[i] - '0';
            else
                ec += num[i] - '0';
        }

        if(oc == ec)
            return true;
        return false;
    }
};