// leet338
package main

import "fmt"

func countBits(num int) []int {
	v := make([]int, num+1)
	for i := 1; i <= num; i++ {
		v[i] = v[i-(i&-i)] + 1
	}
	return v
}
func main() {
	fmt.Println(countBits(10))
}
