func findMissingAndRepeatedValues(grid [][]int) []int {
    n := len(grid);
    bound := n * n;
    mp := make(map[int]int)

    for i := 0; i < n; i++{
        for j := 0; j < n; j++{
            mp[grid[i][j]]++;
        }
    }

    repeated, missing := 0, 0
    for key := 1; key <= bound; key++{
        if mp[key] > 1{
            repeated = key
        }
        if mp[key] == 0{
            missing = key
        }
    }

    return []int{repeated, missing}
}