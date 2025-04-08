func minimumOperations(nums []int) int {
    mp := make(map[int]int)
    sz := len(nums)
    for i := 0; i < sz; i++ {
        mp[nums[i]]++;
    } 

    if sz == len(mp) {
        return 0;
    }

    op := 0;
    i := 0;

    for{
        for j := 0; j < 3 && i < len(nums); j++ {
            mp[nums[i]]--
            if mp[nums[i]] == 0 {
                delete(mp, nums[i])
            }
            sz--
            i++
        }
        if len(mp) == sz {
            break
        }
        op++
    }
    return op + 1;
}