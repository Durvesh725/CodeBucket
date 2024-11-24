class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        long long sum = 0; 
        int smallest = INT_MAX, num = 0, neg = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] < 0)
                    neg++;

                num = abs(matrix[i][j]);
                smallest = min(smallest, num);
                sum += num;
            }
        }

        if(neg%2 == 0)
            return sum;
        
        sum -= smallest;
        sum = sum + (-smallest);
        return sum;
    }
};