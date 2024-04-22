class Solution {
private:
    char turnRight(char ch){
        return (ch == '9' ? '0' : ch + 1);
    }

    char turnLeft(char ch){
        return (ch == '0' ? '9' : ch - 1);
    }

    vector<string> getNeighbours(string s){
        //2options: right or left
        vector<string> temp;
        for(int i = 0; i < 4; i++){
            string option = s;
            option[i] = turnRight(s[i]);
            temp.push_back(option);
            option[i] = turnLeft(s[i]);
            temp.push_back(option);
        }
        return temp;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_map<string, bool> vis;
        q.push("0000");
        vis["0000"] = true;
        int level = 0;
        unordered_set<string> deadendset(deadends.begin(), deadends.end());

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string s = q.front();
                q.pop();

                if(s == target) return level;
                if(deadendset.find(s) != deadendset.end())  continue;

                for(string options: getNeighbours(s)){
                    if(!vis[options]){
                        q.push(options);
                        vis[options] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};