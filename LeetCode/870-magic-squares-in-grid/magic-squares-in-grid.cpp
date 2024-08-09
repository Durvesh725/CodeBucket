class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        unordered_set<int> st;

        if(n < 3 || m < 3)
            return 0;

        const int sum = 15;
        const int dia_sum = 10;

        for(int l = 0; l <= n - 3; l++){
            for(int k = 0; k <= m - 3; k++){

                st.clear();
                bool isMagic = true;

                for(int i = 0; i < 3; i++){
                    int s = 0;
                    for(int j = 0; j < 3; j++){
                        int val = grid[l + i][k + j];
                        if(val < 1 || val > 9 || st.count(val)){
                            isMagic = false;
                            break;
                        }

                        st.insert(val);
                        s += val;
                    }

                    if(s != sum){
                        isMagic = false;
                        break;
                    }
                }

                
                for(int j = 0; j < 3; j++){
                    int s = 0;
                    for(int i = 0; i < 3; i++){
                        s += grid[l + i][k + j];
                    }

                    if(s != sum){
                        isMagic = false;
                        break;
                    }
                }

                
                if(grid[l][k] + grid[l + 2][k + 2] != dia_sum ||
                   grid[l][k + 2] + grid[l + 2][k] != dia_sum){
                    isMagic = false;
                }

                if(isMagic && st.size() == 9) {
                    count++;
                }
            }
        }
        return count;
    }
};
