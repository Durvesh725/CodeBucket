class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int g = 0, i = 1, n = colors.size();
        if((colors[0] != colors[n-1]) && (colors[0] != colors[0+1]))
            g++;
        
        if((colors[n-1] != colors[n-2]) && (colors[n-1] != colors[0])){
            g++;
        }
        
        while(i < n-1){
            if((colors[i] != colors[i-1]) && (colors[i] != colors[i+1]))
                g++;
            i++;
        }
        return g;
    }
};