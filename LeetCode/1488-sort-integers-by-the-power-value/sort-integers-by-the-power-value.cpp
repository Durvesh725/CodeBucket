class Solution {
public:
    int powerSteps(int n){
        int s = 0;

        while(n != 1){
            if(n % 2 == 0){
                n /= 2;
                s++;
            }
            else{
                n = 3 * n + 1;
                s++;
            }
        }

        return s;
    }

    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = lo; i <= hi; i++){
            int power = powerSteps(i);
            pq.push({power, i});
        }

        int res = 0;
        while(!pq.empty() && k){
            res = pq.top().second;
            pq.pop();
            k--;
        }

        return res;
    }
};