// package main

import (
	"fmt"
)

const N = 5
var dp [][]int
var n, i int

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func dfs(left int, right int, nums []int) int {
	if left > right {
		return 0
	}
    if dp[left][right] != -1 {
        return dp[left][right]
	}
	res := -1
    for i := left; i <= right; i++ {
		tmp := dfs(left, i - 1, nums) + dfs(i + 1, right, nums);
		val := 1
		if left - 1 >= 0 {
			val *= nums[left - 1]
		}
		if right + 1 <= n - 1 {
			val *= nums[right + 1]
		}
		res = max(res, tmp + val * nums[i])
	}
	dp[left][right] = res
	return res
}

func maxCoins(nums []int) int {

	n = len(nums)
	if n == 0 {
		return 0
	}
	
    dp = make([][]int, N);
    for i := 0; i < n; i++ {
        dp[i] = make([]int, N)
    }
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            dp[i][j] = -1;
        }
    }
    return dfs(0, n - 1, nums);
}

func main() {
	x := []int{3, 1, 5, 8}
	fmt.Println(maxCoins(x))
}