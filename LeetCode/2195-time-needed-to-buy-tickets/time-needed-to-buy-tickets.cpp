class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        queue<int> q;
        int n = t.size();
        for(int i = 0; i < t.size(); i++)   q.push(i);

        int time = 0;
        while(!q.empty()){
            time++;
            int ind = q.front();
            q.pop();

            t[ind]--;
            if(ind == k && t[ind] == 0) return time;
            if(t[ind] != 0)  q.push(ind);
        }
        return time;
    }
};