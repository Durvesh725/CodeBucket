class Solution {
public:
    long long solve(string &number, int limit, string suff){
        // edge case-1
        if(number.length() < suff.length()){
            return 0;
        }

        long long count = 0;

        // get the trailing str of original number
        string trailStr = number.substr(number.length() - suff.length());
        // get remaining len of the original string after given suffix is replaced in it
        int remainLen = number.length() - suff.length();

        // for rest of the string, count number of digits that can be formed
        for(int i = 0; i < remainLen; i++){
            int digit = number[i] - '0';
            if(digit <= limit){
                count += digit * pow(limit+1, remainLen - i - 1);
            } else{
                count += pow(limit+1, remainLen - i);
                return count;
            }
        }

        // edge case-2: if trailing str i.e number is greater than given suffix, see for number 215
        if(trailStr >= suff){
            count += 1;
        }

        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start-1);
        string endStr = to_string(finish);

        return solve(endStr, limit, s) - solve(startStr, limit, s);
    }
};

// upsolved