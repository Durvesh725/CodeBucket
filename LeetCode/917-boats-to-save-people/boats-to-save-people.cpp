class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(), p.end());
        int n = p.size();
        int i = 0, b = 0, j = n - 1;
        while(i <= j){
            if(p[j] == limit){
                b++;
                j--;
            }
            else{
                if(p[j] + p[i] <= limit){
                    b++;
                    i++;
                }
                else{
                    b++;
                }
                j--;
            }
        }
        return b;
    }
};