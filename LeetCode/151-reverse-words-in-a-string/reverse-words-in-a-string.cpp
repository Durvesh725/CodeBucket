class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0, end = 0, n = s.size();
        string res = "";

        while(start < n){
            while(start < n && s[start] == ' ')
                start++;

            if(start >= n)  break;

            end = start;
            while(end < n && s[end] != ' ')
                end++;
            
            if(!res.empty()){
                res += " ";
            }
            string word = s.substr(start, end-start);
            reverse(word.begin(), word.end());
            res += word;

            start = end;

            // cout << start << " " << end << endl;
        }

        return res;
    }
};