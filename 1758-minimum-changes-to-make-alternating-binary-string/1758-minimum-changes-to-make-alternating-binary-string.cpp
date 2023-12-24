class Solution {
private:
    int solve(string &s, char ch){
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ch)
                count++;
            
            if(ch == '1')
                ch = '0';
            else
                ch = '1';
        }
        return count;
    }
    
public:
    int minOperations(string s) {
        return min(solve(s, '1'), solve(s, '0'));
    }
};