class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i = 0, j = 0;
        int window = 1;
        int unsatisfied = 0, maxi = 0;
        int n = customers.size();

        while(j < n){
            if(grumpy[j] == 1 && customers[j] > 0){
                unsatisfied += customers[j];
            }

            if(window == minutes){
                maxi = max(maxi, unsatisfied);
                if(grumpy[i] == 1){
                    unsatisfied -= customers[i];
                }
                i++;
                window--;
            }
            
            j++;
            window++;
        }

        int already_satisfied = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                already_satisfied += customers[i];
            }
        }

        return already_satisfied + maxi;
    }
};