class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        int pieces_a = 0, pieces_b = 0;
        int n = colors.size();

        if(n < 3)
            return false;

        int ca = 0, cb = 0;
        for(int i = 0; i < n; i++){
            if(colors[i] == 'A'){
                a++;
                if(a >= 3)
                    pieces_a++;
                b = 0;
            }
            else{
                b++;
                if(b >= 3){
                    pieces_b++;
                }
                a = 0;
            }
        }

        return pieces_a > pieces_b;
    }
};