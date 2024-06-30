class Solution {
public:
    int solve(int red, int blue, bool turn){
        int row_count = 1;
        while(true){
            if(turn){
                if(red >= row_count){
                    red -= row_count;
                    row_count++;
                    turn = false;
                }
                else{
                    break;
                }
            }
            else{
                if(blue >= row_count){
                    blue -= row_count;
                    row_count++;
                    turn = true;
                }
                else{
                    break;
                }
            }
        }

        return row_count - 1;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red, blue, true), solve(red, blue, false));
    }
};