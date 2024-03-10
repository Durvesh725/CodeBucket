class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& words) {
        vector<string> res;
        for(const string &word: words){
            string shortest = "";
            bool fShortest = false;
            //substrings
            for(int i = 0; i < word.size(); i++){
                for(int len = 1; len <= word.size()-i; len++){
                    string substring = word.substr(i, len);
                    bool isUnique = true;
                    //iterate over rest of the strings to check whether the current substr exists in other words
                    for(const string &otherword: words){
                        if(&otherword != &word && otherword.find(substring) != string::npos){
                            isUnique = false;
                            break;
                        }
                    }

                    if(isUnique){
                        if(!fShortest || substring.size() < shortest.size() || (substring.size() == shortest.size() && 
                        substring < shortest)){
                            shortest = substring;
                            fShortest = true;
                        }
                    }
                }
            }
            res.push_back(shortest);
        }
        return res;
    }
};