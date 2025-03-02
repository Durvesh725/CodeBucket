func mergeArrays(nums1 [][]int, nums2 [][]int) [][]int {
    n, m := len(nums1), len(nums2);
    ans := make([][]int, 0);
    i, j := 0, 0;

    for i < n && j < m{
        if nums1[i][0] == nums2[j][0]{
            ans = append(ans, []int{nums1[i][0], nums1[i][1] + nums2[j][1]})
            i++;
            j++;
        } else if nums1[i][0] < nums2[j][0]{
            ans = append(ans, nums1[i]);
            i++;
        } else{
            ans = append(ans, nums2[j]);
            j++;
        }
    }

    for i < n{
        ans = append(ans, nums1[i]);
        i++;
    }

    for j < m{
        ans = append(ans, nums2[j]);
        j++;
    }

    return ans;
}