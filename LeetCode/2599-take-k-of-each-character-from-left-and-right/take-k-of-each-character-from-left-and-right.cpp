class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0){
            return 0;
        }

        int n = s.size();
        int ac = count(s.begin(), s.end(), 'a');
        int bc = count(s.begin(), s.end(), 'b');
        int cc = count(s.begin(), s.end(), 'c');

        if(ac < k || bc < k || cc < k)
            return -1;

        vector<int> prea(n), preb(n), prec(n);
        if(s[0] == 'a') prea[0] = 1;
        if(s[0] == 'b') preb[0] = 1;
        if(s[0] == 'c') prec[0] = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == 'a') prea[i] = prea[i-1] + 1;
            else    prea[i] = prea[i-1];
            if(s[i] == 'b') preb[i] = preb[i-1] + 1;
            else    preb[i] = preb[i-1];
            if(s[i] == 'c') prec[i] = prec[i-1] + 1;
            else    prec[i] = prec[i-1];
        }

        vector<int> suffa(n, 0), suffb(n, 0), suffc(n, 0);
        if(s[n - 1] == 'a') suffa[n - 1] =  1;
        if(s[n - 1] == 'b') suffb[n - 1] = 1;
        if(s[n - 1] == 'c') suffc[n - 1] =  1;
        for(int i = n - 2; i >= 0; --i){
            if(s[i] == 'a') suffa[i] = suffa[i + 1] + 1;
            else    suffa[i] = suffa[i + 1];
            if(s[i] == 'b') suffb[i] = suffb[i + 1] + 1;
            else    suffb[i] = suffb[i + 1];
            if(s[i] == 'c') suffc[i] = suffc[i + 1] + 1;
            else    suffc[i] = suffc[i + 1];
        }

        int ans = n;
        for(int i = n; i >= 0; i--){
            int aac = (i < n) ? suffa[i] : 0;
            int bbc = (i < n) ? suffb[i] : 0;
            int ccc = (i < n) ? suffc[i] : 0;

            int rema = k - aac;
            int remb = k - bbc;
            int remc = k - ccc;

            if(rema <= 0 && remb <= 0 && remc <= 0){
                ans = min(ans, n - i);
                break;
            }

            auto ita = lower_bound(begin(prea), begin(prea) + i - 1, rema);
            auto itb = lower_bound(begin(preb), begin(preb) + i - 1, remb);
            auto itc = lower_bound(begin(prec), begin(prec) + i - 1, remc);

            int mx = max({ita - prea.begin(), itb - preb.begin(), itc - prec.begin()});

            ans = min(ans, mx + (n - i + 1));
        }

        return ans;

    }
};