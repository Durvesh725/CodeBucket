class Solution {
public:
    int maxBottlesDrunk(int nb, int nex) {
        int emb = nb;
        int ans = nb;
        int cnt = 0;
        while(nex <= emb){
            emb = emb - nex;
            cnt++;
            nex++;
        }
        if(cnt + emb >= nex){
            cnt++;
            emb -= nex;
            nex++;
        }
        
        return ans + cnt;
    }
};