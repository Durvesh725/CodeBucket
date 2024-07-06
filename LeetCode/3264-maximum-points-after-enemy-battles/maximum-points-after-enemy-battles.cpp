class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergy, int currentEnergy) {
        sort(enemyEnergy.begin(), enemyEnergy.end());
        if(enemyEnergy[0] > currentEnergy)
            return 0;
            
        long long p = 0;
        int n = enemyEnergy.size();
        int j = n - 1;
        while(j >= 0){
            if(currentEnergy >= enemyEnergy[0]){
                p += currentEnergy/enemyEnergy[0];
                currentEnergy %= enemyEnergy[0];
            }
            else{
                if(p >= 1){
                    currentEnergy += enemyEnergy[j];
                    j--;
                }
                else{
                    break;
                }
            }
        }

        return p;
    }
};