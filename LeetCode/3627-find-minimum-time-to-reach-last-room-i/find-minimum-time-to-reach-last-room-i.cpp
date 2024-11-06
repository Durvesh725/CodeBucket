class Solution {
public:
    const vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> visTime(n, vector<int>(m, INT_MAX));
        visTime[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto[currTime, x, y] = pq.top();
            pq.pop();

            if(x == n-1 && y == m-1)
                return currTime;
            
            if(currTime > visTime[x][y])
                continue;

            for(auto[nx, ny]: dir){
                int newX = x + nx;
                int newY = y + ny;

                if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                    int waitTime = max(currTime, moveTime[newX][newY]) + 1;
                    if(waitTime < visTime[newX][newY]){
                        visTime[newX][newY] = waitTime;
                        pq.push({waitTime, newX, newY});
                    }
                }
            }
        }

        return -1;
    }
};