class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> maxfreq;
        for(string &s: words2){
            unordered_map<char, int> freq;
            for(char ch: s){
                freq[ch]++;
                maxfreq[ch] = max(maxfreq[ch], freq[ch]);
            }
        }

        vector<string> res;
        for(string &s: words1){
            unordered_map<char, int> um;
            for(char &ch: s){
                um[ch]++;
            }

            bool f = true;
            for(auto &[ch, maxCount]: maxfreq){
                if(um[ch] < maxCount){
                    f = false;
                    break;
                }
            }

            if(f){
                res.push_back(s);
            }
        }

        return res;
    }
};