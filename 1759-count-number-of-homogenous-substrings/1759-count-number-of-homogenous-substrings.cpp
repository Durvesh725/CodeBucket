class Solution {
public:
    int countHomogenous(string s) {
        //bruteforce
        // long long cnt = 0;
        // for(int i = 0; i < s.size(); i++){
        //     for(int j = i; j < s.size(); j++){
        //         if(s[i] == s[j]){
        //             cnt++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return cnt;
        
        //optimal: for every longest homo substring, the substring inside it will also be homo
        //let size of longest substring be n: n*(n+1)/2;
        
        long long int maxCount = 0;
        int mod = 1000000007;
        for(int i = 0; i < s.length();){
            long long int cnt = 0;
            char ch = s[i];
            while(i < s.length() && s[i] == ch){
                cnt++;
                i++;
            }
            maxCount += ((cnt* (cnt+1))/2)%mod;      
        }
        return (int)maxCount%mod;
    }
};