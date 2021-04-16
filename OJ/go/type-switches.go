package main

import (
	"fmt"
)

func do(i interface{}) {
	switch v := i.(type) {
	case int:
		fmt.Printf("%v, %T \n", v, v)
	case string:
		fmt.Printf("%q is %v bytes long \n", v, len(v))
	default:
		fmt.Printf("I don't know the type %T\n", v)
	}
}

func main() {
	do(10)
	do("hello")
	do(true)
}
