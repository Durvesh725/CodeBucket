func applyOperations(nums []int) []int {
    for i := range nums[:len(nums)-1]{
        if nums[i] == nums[i+1]{
            nums[i] *= 2
            nums[i+1] = 0
        }
    }

    i := 0;
    for j := 0; j < len(nums); j++{
        if nums[j] != 0{
            nums[i], nums[j] = nums[j], nums[i]
            i++
        }
    }

    return nums
}