class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        bool turn = 1;
        int i = 0, j = 0;
        string res = "";

        while(i < size1 && j < size2){
            if(turn){
                res.push_back(word1[i]);
                turn = 0;
                i++;
            }
            else{
                res.push_back(word2[j]);
                turn = 1;
                j++;
            }
        }

        while(i < size1){
            res.push_back(word1[i++]);
        }

        while(j < size2){
            res.push_back(word2[j++]);
        }

        return res;
    }
};