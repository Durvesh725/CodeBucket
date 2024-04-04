class Solution {
public:
    int maxDepth(string s) {
        int open = 0, maxi = INT_MIN;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                open++;
            if(s[i] == ')')
                open--;
            
            maxi = max(maxi, open);
        }      
        return maxi;
    }
};