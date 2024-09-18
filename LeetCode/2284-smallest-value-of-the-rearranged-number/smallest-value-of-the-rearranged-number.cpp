class Solution {
public:
    long long smallestNumber(long long num) {
        string n = to_string(num);
        vector<char> temp;
        for(char ch: n){
            temp.push_back(ch);
        }

        string res = "";
        bool isZero = false;
        if(num > 0){
            sort(temp.begin(), temp.end());

            string zeros = "";
            int i = 0;
            while(temp[i] == '0'){
                isZero = true;
                zeros.push_back('0');
                i++;
            }

            if(isZero){
                res.push_back(temp[i]);
                res.append(zeros);
            }

            i = (isZero) ? i+1 : 0;

            for(; i < temp.size(); i++){
                res.push_back(temp[i]);
            }
        }
        else{
            sort(temp.begin(), temp.end(), greater<int>());
            res.push_back('-');
            for(auto it: temp)
                res.push_back(it);
        }

        return stoll(res);
    }
};