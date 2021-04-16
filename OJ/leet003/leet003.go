// leet003
package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	// 0ms,  Time O(N) Space O(1)
	// f[i] 记录 s[0..=i] 的最长不含重复字符的字串长度
	// prev[i] 记录 s[i] 的上一次出现位置
	prev := make([]int, 255)
	f, ans := 0, 0
	for i, si := range s {
		f = min(f, i-prev[si]) + 1
		prev[si] = i + 1
		ans = max(ans, f)
	}
	return ans
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	fmt.Println(lengthOfLongestSubstring("abcabcbb"))
	fmt.Println(lengthOfLongestSubstring("bbbbb"))
	fmt.Println(lengthOfLongestSubstring("pwwkew"))
}
