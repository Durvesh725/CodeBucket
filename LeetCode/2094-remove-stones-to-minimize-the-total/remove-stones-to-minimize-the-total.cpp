class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        int res = 0;
        for(int &n: piles){
            pq.push(n);
            res += n;
        }

        while(k){
            int pile = pq.top();
            pq.pop();

            int toRemove = static_cast<int>(pile/2);
            pq.push(pile - toRemove);
            res -= toRemove;
            k--;
        }

        return res;
    }
};