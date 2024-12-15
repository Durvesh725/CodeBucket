class Solution {
public:
    double benefit(int pass, int total){
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();

        for(int i = 0; i < n; i++){
            pq.push({benefit(classes[i][0], classes[i][1]), i});
        }

        while(extraStudents){
            int ind = pq.top().second;
            pq.pop();

            classes[ind][0] += 1;
            classes[ind][1] += 1;

            pq.push({benefit(classes[ind][0], classes[ind][1]), ind});
            extraStudents--;
        }

        double avgPassRatio = 0;
        for(auto &it : classes){
            avgPassRatio += (double)it[0] / it[1];
        }

        return avgPassRatio / n;
    }
};