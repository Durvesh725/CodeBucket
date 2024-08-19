class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& words) {
        unordered_map<char, int> um;
        unordered_map<char, int> temp;

        int n = l.size();

        for(int i = 0; i < n; i++){
            if(l[i] >= 'a' && l[i] <= 'z'){
                um[l[i]]++;
            }

            if(l[i] >= 'A' && l[i] <= 'Z'){
                char ch = tolower(l[i]);
                um[ch]++;
            }
        }

        int shortestLen = INT_MAX;
        string ans = "";

        for(int i = 0; i < words.size(); i++){
            temp = um;
            string w = words[i];
            // cout << w << endl;
            for(auto it: w){
                if(temp.find(it) != temp.end()){
                    temp[it]--;
                    if(temp[it] == 0)
                        temp.erase(it);
                }
            }

            
            cout << temp.size() << endl;
            for(auto it: temp){
                cout << it.first << " " << it.second;
            }

            if(temp.size() == 0){
                if(w.size() < shortestLen){
                    shortestLen = w.size();
                    ans = w;
                }
            }
        }

        return ans;
    }
};