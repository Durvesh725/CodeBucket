class Solution {
public:
    int romanToInt(string str) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int sum = 0;
        int n = str.size();
        for(int i = 0; i < n-1; i++){
            if(mp[str[i]] < mp[str[i+1]]){
                sum = sum - mp[str[i]];
            }
            else{
                sum = sum + mp[str[i]];
            }
        }
        sum = sum + mp[str[n-1]];
        return sum;
    }
};