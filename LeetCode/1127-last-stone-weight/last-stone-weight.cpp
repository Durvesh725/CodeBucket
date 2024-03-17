class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size() != 1 && pq.size()){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a-b > 0)
                pq.push(a-b);
        }

        if(pq.size())
            return pq.top();
        return 0;
    }
};

//8 7 4 2 1 1 
// 4 2 1 1 1 
//2 1 1 1
//1 1 1
//1
