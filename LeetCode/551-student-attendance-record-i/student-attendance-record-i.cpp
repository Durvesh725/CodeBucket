class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int c_late = 0;
        int i = 0;
        int n = s.size();
        while(i < n){
            if(s[i] == 'A')
                absent++;

            if(s[i] == 'L')
                c_late++;
            else
                c_late = 0;

            if(absent >= 2 || c_late >= 3)  return false;

            i++;
        }
        return true;
    }
};