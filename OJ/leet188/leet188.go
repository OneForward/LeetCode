// leet188
package main

import (
	"fmt"
	"math"
)

func maxProfit(K int, prices []int) int {
	sell := make([]int, K+1)
	buy := make([]int, K+1)
	for i := range buy {
		buy[i] = math.MinInt32
	}
	for _, x := range prices {
		for k := 1; k <= K; k++ {
			buy[k] = max(sell[k-1]-x, buy[k])
			sell[k] = max(buy[k]+x, sell[k])
		}
	}
	return sell[K]
}

func max(x int, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	fmt.Println(maxProfit(2, []int{2, 4, 1}))
}
