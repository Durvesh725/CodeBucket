func minIncrementForUnique(nums []int) int {
    sort.Ints(nums)
    moves := 0
    sz := len(nums)

    for i := 0; i < sz - 1; i++ {
        if nums[i] == nums[i+1] {
            nums[i+1] = nums[i+1] + 1
            moves++
        } else if nums[i+1] < nums[i] {
            diff := (nums[i] - nums[i+1]) + 1
            moves += diff
            nums[i+1] = nums[i+1] + diff
        }
    }

    return moves
}