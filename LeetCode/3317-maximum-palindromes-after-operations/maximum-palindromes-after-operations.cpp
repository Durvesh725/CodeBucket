class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        //go on filling from smaller word pos to bigger
        //1. find the word sizes
        vector<int> wordSize;
        for(auto &it: words){
            wordSize.push_back(it.length());
        }   
        sort(wordSize.begin(), wordSize.end());

        //2. store fre of each char of all the words
        unordered_map<char, int> freq;
        for(auto &it: words){
            for(char c: it)
                freq[c]++;
        }

        //3. find even pair count and odd pair count
        int evenP = 0, oddP = 0;
        for(auto it: freq){
            evenP += it.second/2;
            oddP += it.second%2;
        }

        //main
        int ans = 0;
        for(int i = 0; i < wordSize.size(); i++){
            //if odd word length
            if(wordSize[i]%2 == 1){
                if(oddP){
                    oddP--;
                }
                else{
                    //borrowing concept
                    evenP--;
                    oddP++;  
                    // neutralize the odd value as after borrowing one pair we are using one value again
                }
            }
            if(evenP < wordSize[i]/2)    break;
            evenP -= wordSize[i]/2;
            ans++;
        }
        return ans;
    }
};