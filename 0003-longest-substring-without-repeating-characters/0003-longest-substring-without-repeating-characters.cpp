class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         //frequency map
//         vector<int> mp(256, -1);
//         int left = 0, right = 0;
//         int len = 0;
//         int n = s.length();
//         while(right < n){
//             //if pos of particular char already exists in a map
//             if(mp[s[right]] != -1)
//                 left = max(mp[s[right]] + 1, left);
            
//             mp[s[right]] = right;
            
//             len = max(len, right-left+1);
//             right++;
//         }
//         return len;
        
        //set approach
        int len = 0;
        int left = 0;
        set<char> ss;
        
        for(int i = 0; i < s.size(); i++){
            int currSize = ss.size();            
            ss.insert(s[i]);
            
            //duplicate element has occured
            if(currSize == ss.size()){
                while(s[left] != s[i]){
                    ss.erase(s[left]);
                    left++;   
                }   
                
                left++;
            }
            
            len = max(len, i - left + 1);
        }
        return len;
    }
};