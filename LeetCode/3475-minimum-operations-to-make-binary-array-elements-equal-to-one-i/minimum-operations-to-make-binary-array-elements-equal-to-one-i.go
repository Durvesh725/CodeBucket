func minOperations(nums []int) int {
    var op int = 0;
    n := len(nums);
    for i := 0; i < n; i++{
        if nums[i] == 0 {
            if i + 2 >= n{
                return -1;
            }
            
            for j := 0; j < 3; j++{
                nums[i + j] = 1 - nums[i + j]
            }

            op++;
        }
    }

    for i := 0; i < n; i++{
        if nums[i] == 0{
            return -1;
        }
    } 

    return op;
}