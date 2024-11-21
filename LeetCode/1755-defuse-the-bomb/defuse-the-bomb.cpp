class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);

        if(k > 0){
            for(int i = 0; i < n; i++){
                int j = i+1, sum = 0, t = k;
                while(t){
                    sum += code[j % n];
                    j++, t--;
                }
                res[i] = sum;
            }
        }
        else if(k < 0){
            for(int i = 0; i < n; i++){
                int j = i-1, sum = 0, t = abs(k);
                while(t){
                    sum += (j >= 0) ? code[j] : code[n + j];
                    j--, t--;
                }
                res[i] = sum;
            }
        }

        return res;
    }
};