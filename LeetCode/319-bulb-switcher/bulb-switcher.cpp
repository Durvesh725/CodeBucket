class Solution {
public:
    int bulbSwitch(int n) {
        //we can observe that only the bulbs which are perfect squares remains on
        //number of blubs ON is equal to the sqrt of n
        // vector<int> blub(n, false);
        // for(int r = 1; r <= n; r++){
        //     for(int i = r-1; i < n; i+= r){
        //         blub[i] = !blub[i];
        //     }
        // }

        // int ans = 0;
        // for(auto it: blub){
        //     if(it == true)
        //         ans++;
        // }

        // return ans;

        return sqrt(n);
    }
};

//perfect squares: 
//square of another number
//odd no. of factors
//In base 10, a perfect square can end only in 0, 1, 4, 5, 6, or 9.