class Solution {
public:
    bool backspaceCompare(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        int i = 0;
        string ans1 = "";
        string ans2 = "";
        
        while(i < n1){
            if(ans1.size() > 0 && s1[i] == '#'){
                ans1.pop_back();
            }
            else if(s1[i] != '#'){
                ans1.push_back(s1[i]);
            }
            i++;
        }
        
        i = 0;
        
        while(i < n2){
            if(ans2.size() > 0 && s2[i] == '#'){
                ans2.pop_back();
            }
            else if(s2[i] != '#'){
                ans2.push_back(s2[i]);
            }
            i++;
        }
        
        return ans1 == ans2;
    }
};