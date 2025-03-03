func pivotArray(nums []int, pivot int) []int {
    n := len(nums)
    res := make([]int, n);
    left, right := 0, n-1;
    i, j := 0, n-1;
   
    for i < n && j >= 0{
        if nums[i] < pivot{
            res[left] = nums[i];
            left++;
        } 
        if nums[j] > pivot{
            res[right] = nums[j];
            right--;
        }
        i++;
        j--;
    }

    for left <= right{
        res[left] = pivot;
        left++;
    }

    return res;
}