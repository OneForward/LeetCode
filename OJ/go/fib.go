package main

func fib(n int, c chan int) {
	a, b := 0, 1
	for i := 0; i < n; i++ {
		c <- a
		a, b = b, a+b
	}
	close(c)
}

func main() {
	c := make(chan int, 10)
	go fib(cap(c), c)
	for x := range c {
		println(x)
	}
}
