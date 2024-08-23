class Solution {
public:
    string fractionAddition(string exp) {
        int num = 0, deno = 1;
        int n = exp.size();
        int i = 0;
        bool isNeg = false;

        while(i < n){
            int currNum = 0;
            int currDeno = 0;

            isNeg = (exp[i] == '-') ? true: false;

            if(exp[i] == '+' || exp[i] == '-'){
                i++;
            }

            while(i < n && isdigit(exp[i])){
                currNum = (currNum * 10) + (exp[i] - '0');
                i++;
            }

            if(isNeg){
                currNum = currNum * -1;
            }

            i++;

            while(i < n && isdigit(exp[i])){
                currDeno = (currDeno * 10) + (exp[i] - '0');
                i++;
            }

            num = (num * currDeno) + (currNum * deno);
            deno = deno * currDeno;
        }

        int gcd = abs(__gcd(num, deno));
        num = num/gcd;
        deno = deno/gcd;

        return to_string(num) + "/" + to_string(deno);
    }
};