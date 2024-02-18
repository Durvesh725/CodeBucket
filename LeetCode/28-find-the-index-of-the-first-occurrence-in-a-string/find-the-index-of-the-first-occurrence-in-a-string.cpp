class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        for(int i = 0; i < haystack.size(); i++){
            if(needle == haystack.substr(i, len))
                return i;
        }
        return -1;
    }
};