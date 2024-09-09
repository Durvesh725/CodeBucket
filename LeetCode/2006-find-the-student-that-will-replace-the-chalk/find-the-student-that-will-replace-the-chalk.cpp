class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;

        for(auto it: chalk){
            sum += it;
        }

        k = k % sum;

        int i = 0;
        while(true){
            if(chalk[i] > k){
               return i;
            }
            k -= chalk[i];
            i++;
            if(i == n)
                i = 0;
        }
        return -1;
    }
};