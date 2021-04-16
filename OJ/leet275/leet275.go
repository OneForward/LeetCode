// leet275
package main

import "fmt"

func hIndex(citations []int) int {
	n := len(citations)
	lft, rht := 0, n
	for lft < rht {
		mid := (lft + rht) / 2
		if citations[mid]+mid >= n {
			rht = mid
		} else {
			lft = mid + 1
		}
	}
	return n - lft
}

func main() {
	fmt.Println(hIndex([]int{0, 1, 3, 5, 6}))
}
