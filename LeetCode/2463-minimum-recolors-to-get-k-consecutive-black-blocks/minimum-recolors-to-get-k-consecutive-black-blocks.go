func minimumRecolors(blocks string, k int) int {
    n := len(blocks)
    pre := make([]int, n)
    if blocks[0] == 'B'{
        pre[0] = 1
    }

    for i := 1; i < n; i++{
        if blocks[i] == 'B'{
            pre[i] = pre[i-1] + 1
        } else{
            pre[i] = pre[i-1]
        }
    }

    mini := math.MaxInt32
    i := 0
    for i <= n - k{
        var op int
        if i == 0{
            op = k - pre[i + k - 1]
        } else{
            op = k - (pre[i + k - 1] - pre[i - 1])
        }
        if op < mini{
            mini = op
        }
        i++
    }

    return mini
}