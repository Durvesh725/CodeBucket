class Solution:
    def minimumOperations(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        op = 0

        for j in range(n):
            for i in range(1, m):
                if grid[i][j] <= grid[i-1][j]:
                    inc = grid[i-1][j] - grid[i][j] + 1;
                    grid[i][j] += inc;
                    op += inc;
        
        return op;
        