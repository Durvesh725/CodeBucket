class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        // queue<int> q;
        // int n = t.size();
        // for(int i = 0; i < t.size(); i++)   q.push(i);

        // int time = 0;
        // while(!q.empty()){
        //     time++;
        //     int ind = q.front();
        //     q.pop();

        //     t[ind]--;
        //     if(ind == k && t[ind] == 0) return time;
        //     if(t[ind] != 0)  q.push(ind);
        // }
        // return time;

        //intuition: do a dry run for all passes and observer left and right of kth position
        int time = 0;
        int n = t.size();
        for(int i = 0; i < n; i++){
            if(i <= k)  time += min(t[i], t[k]);
            else time += min(t[i], t[k]-1);
        }
        return time;
    }
    //TC: N*max(tickets[i]);
};