class Solution {
public:
    int minChanges(int n, int k) {
        if(n == k)
            return 0;

        bitset<32> n1(n);
        bitset<32> k1(k);
        int changes = 0;

        for(int i = 0; i < 32; i++){
            if(n1[i] == 1 && k1[i] == 0){
                changes++;
            }
            else if(n1[i] == 0 && k1[i] == 1){
                return -1;
            }
        }

        return changes;
    }
};