class Solution {
public:
    bool check(string &s){
        int n = s.size();
        sort(s.begin(), s.end());

        return s[0] == s[n-1];
    }

    int maximumLength(string s) {
        unordered_map<string, int> um;
        int n = s.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                // um[s.substr(i, j - i + 1)].first = (j - i) + 1;
                string sub = s.substr(i, j-i+1);
                if(check(sub))
                    um[sub]++;
            }
        }

        int len = -1;
        for(auto it: um){
            if(it.second >= 3){
                len = max(len, (int)it.first.size());
            }
        }

        // for(auto it: um){
        //     cout << it.first << " " << it.second << endl;
        // }

        return len;
    }
};