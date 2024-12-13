using ll = long long;

class Solution {
public:
    bool countCars(ll minutes, vector<int> &ranks, int &cars){
        ll cc = 0;
        for(auto r: ranks){
            ll t = minutes/r;
            cc += floor(sqrt(t));
        }

        return (cc >= cars);
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = 1e14;

        while(l < r){
            ll mid = (l+r)/2;
            if(countCars(mid, ranks, cars)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }

        return l;
    }
};

// x = r * n^2
// x/r = n^2
// sqrt(x/r) = n
// therefore no. of cars each mechanic can repair can be found out by above formula
// bin search on ans (i.e put search on no. of minutes)