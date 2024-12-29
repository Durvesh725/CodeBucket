class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)
            return word;
        
        int n = word.size();
        int len = n - (numFriends - 1);
        
        string largest = "";
        for(int i = 0; i < n; i++){
            string s = word.substr(i, len);
            if(s > largest)
                largest = s;
        }

        return largest;
    }
};

//upsolved