class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> cp(n);
        for(int i = 0; i < n; i++){
            cp[i] = {capital[i], profits[i]};
        }

        sort(cp.begin(), cp.end());
        // cout << cp[0].first << cp[0].second;

        priority_queue<int> giveMeMaxProfit;
        int i = 0;
        while(k){
            while(i < n && w >= cp[i].first){
                //store all possible profits that can be buyed with current capital
                giveMeMaxProfit.push(cp[i].second);
                i++;
            }
            // cout << "i: " << i << endl;

            if(giveMeMaxProfit.empty())
                break;

            //once you get all possible profits, select maximum one
            w += giveMeMaxProfit.top();
            giveMeMaxProfit.pop();
            --k;
            // cout << "W: " << w << endl;
        }

        return w;
    }
};

//c, p
//eg:vec = {(0, 1), {1,2}, {1,3}, {2,1}};
//k = 3, w = 0