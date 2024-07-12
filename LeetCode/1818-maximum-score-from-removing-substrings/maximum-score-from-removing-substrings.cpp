class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> v1, v2;
        int ans = 0;
        bool flag = 0;
        if(x > y) flag = 1;

        for(char ch: s){
            if(!v1.empty()){
                if(flag){
                    if(v1.back() == 'a' && ch == 'b'){
                        ans += x;
                        v1.pop_back();
                    }
                    else {v1.push_back(ch); }
                }
                else{
                    if(v1.back() == 'b' && ch == 'a'){
                        ans += y;
                        v1.pop_back();
                    }
                    else {v1.push_back(ch); }
                }
            }
            else {v1.push_back(ch); }
        }

        for(char ch: v1){
            if(!v2.empty()){
                if(!flag){
                    if(v2.back() == 'a' && ch == 'b'){
                        ans += x;
                        v2.pop_back();
                    }
                    else {v2.push_back(ch); }
                }
                else{
                    if(v2.back() == 'b' && ch == 'a'){
                        ans += y;
                        v2.pop_back();
                    }
                    else {v2.push_back(ch); }
                }
            }
            else {v2.push_back(ch); }
        }

        return ans;
    }
};