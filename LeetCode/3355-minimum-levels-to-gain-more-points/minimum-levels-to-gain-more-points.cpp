class Solution {
public:
    int minimumLevels(vector<int>& possibleLevels) {
        int n = possibleLevels.size();
        vector<int> fp(n), bp(n);
        int p = 0;

        for(int i = 0; i < n; i++) {
            p = (possibleLevels[i] == 1) ? p + 1 : p - 1;
            fp[i] = p;
        }

        p = 0; 

        for(int i = n - 1; i >= 0; i--) {
            p = (possibleLevels[i] == 1) ? p + 1 : p - 1;
            bp[i] = p;
        }

        for(int i = 0; i < n - 1; i++) {
            if(fp[i] > bp[i + 1]) {
                return i + 1;
            }
        }

        return -1;
    }
};
