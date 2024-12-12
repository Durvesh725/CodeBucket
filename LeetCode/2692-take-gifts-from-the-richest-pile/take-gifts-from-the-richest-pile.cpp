class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(int &n: gifts){
            pq.push(n);
        }

        while(k){
            int maxGifts = pq.top();
            pq.pop();

            pq.push(static_cast<int>(sqrt(maxGifts)));
            k--;
        }

        long long res = 0;
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};