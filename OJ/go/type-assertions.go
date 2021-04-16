package main

import (
	"fmt"
)

func main() {
	var i interface{}
	describe(i)

	i = 41
	describe(i)

	i = "hello"
	describe(i)

	var i2 interface{} = "hello"

	s := i2.(string)
	fmt.Println(s)

	f, ok := i2.(float32)
	fmt.Println(f, ok)
}

func describe(i interface{}) {
	fmt.Printf("(%v, %T)\n", i, i)
}
