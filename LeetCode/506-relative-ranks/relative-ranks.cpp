class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq; 
        int n = score.size();
        vector<string> res(n);

        for(int i = 0; i < n; i++){
            pq.push({score[i], i});
        }

        int rank = 1;
        while(!pq.empty()){
            auto [s, idx] = pq.top(); 
            pq.pop();

            if(rank > 3){
                res[idx] = to_string(rank);
            }
            else if(rank == 1){
                res[idx] = "Gold Medal";
            }
            else if(rank == 2){
                res[idx] = "Silver Medal";
            }
            else if(rank == 3){
                res[idx] = "Bronze Medal";
            }

            rank++;
        }
        return res;
    }
};
