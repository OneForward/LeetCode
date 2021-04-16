// leet000
package main

import "fmt"

func twoSum(nums []int, target int) []int {
	M := make(map[int]int)
	for i, x := range nums {
		if j, ok := M[target-x]; ok {
			return []int{i, j}
		}
		M[x] = i
	}
	return nil
}

func main() {
	fmt.Println(twoSum([]int{2, 7, 11, 15}, 9))
}
