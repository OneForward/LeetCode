package main

func superEggDrop(K int, N int) int {
	f, T := make([]int, K+1), 0
	for ; f[K] < N; T++ {
		for k := K; k > 0; k-- {
			f[k] = f[k] + f[k-1] + 1
		}
	}
	return T
}

func main() {
	println(superEggDrop(5, 1000))
}
