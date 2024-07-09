class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long ct = customers[0][0] + customers[0][1];
        long wt = ct - customers[0][0];
        for(int i = 1; i < n; i++){
            if(customers[i][0] < ct){
                ct += customers[i][1];
            }
            else{
                ct = customers[i][0] + customers[i][1];
            }
            wt += ct - customers[i][0];
        }
        return ((double(wt) / n));
    }
};