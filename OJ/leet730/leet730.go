package main

import (
	"fmt"
)

const MOD int = 1e9 + 7

func countPalindromicSubsequences(S string) int {
	// 28ms, 动态规划, 自顶向下
	// M[i][j] ： 分别计算 S[i..=j] 中以 a..a , b..b 形式的回文串
	// 先找到 i, j 中最左边和最右边的 a, 记为 i0, j0
	// i0 == -1 说明不存在
	// i0 == j0 只有 1 个回文串 a
	// i0 < j0  f(i, j) = f(i+1, j-1) + 2, 2 是指 a 和 aa 两个串, 其余的都是 a..a 且内部非空的回文串

	n := len(S)
	M := make([][]int, n)
	for i := range M {
		M[i] = make([]int, n)
	}
	next := make([][4]int, n)
	prev := make([][4]int, n)

	last := [4]int{-1, -1, -1, -1}
	for i := range S {
		last[S[i]-'a'] = i
		prev[i] = last
	}
	last = [4]int{-1, -1, -1, -1}
	for i := len(S) - 1; i >= 0; i-- {
		last[S[i]-'a'] = i
		next[i] = last
	}

	var dp func(i, j int) int
	dp = func(i, j int) int {
		if M[i][j] != 0 {
			return M[i][j]
		}

		if i == j {
			return 1
		}

		if i > j {
			return 0
		}

		ans := 0
		for k := 0; k < 4; k++ {
			i0, j0 := next[i][k], prev[j][k]
			if i0 == -1 {
				continue
			}
			if i0 == j0 {
				ans++
			}
			if i0 < j0 {
				ans += 2 + dp(i0+1, j0-1)
				ans %= MOD
			}
		}
		ans %= MOD
		M[i][j] = ans
		return ans
	}
	return dp(0, n-1)
}

func main() {
	fmt.Println(countPalindromicSubsequences("bccb"))
	fmt.Println(countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"))
	fmt.Println(countPalindromicSubsequences("acaccbbdcddaacddaccd"))
}
