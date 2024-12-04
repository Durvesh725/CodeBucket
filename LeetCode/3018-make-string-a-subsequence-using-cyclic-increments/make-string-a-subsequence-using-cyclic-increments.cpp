class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        int j = 0;
        for(int i = 0; i < n1 && j < n2; i++){
            if((str1[i] == 'z' && str2[j] == 'a') || (str1[i] + 1 == str2[j]) || (str1[i] == str2[j]))
                j++;

            if(j == n2)
                return true;
        }

        return false;
    }
};