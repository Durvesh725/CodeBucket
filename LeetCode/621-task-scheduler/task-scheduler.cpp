class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26);
        for(char &ch: tasks){
            mp[ch-'A']++;
        }

        priority_queue<int> pq;
        for(int i = 0; i < mp.size(); i++){
            if(mp[i] > 0)
                pq.push(mp[i]);
        }

        int time = 0;

        vector<int> temp;
        while(!pq.empty()){
            //at max n+1 tasks can be performed i.e if one task is performed, that task can again be performed after n interval
            for(int i = 1; i <= n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            //{0,0..} in temp, then dont push ele onto pq
            for(int i = 0; i < temp.size(); i++){
                if(temp[i] > 0)
                    pq.push(temp[i]);
            }

            //if empty at last, temp will be containing the elements for eg{0, 0} means 2 elements only left
            if(pq.empty())
                time += temp.size();
            else
                time += n+1;
            
            temp.clear();
        }
        return time;
    }
};