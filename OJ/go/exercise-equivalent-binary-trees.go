package main

import "golang.org/x/tour/tree"

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree, ch chan int) {
	var walk func(*tree.Tree)

	walk = func(t *tree.Tree) {
		if t != nil {
			walk(t.Left)
			ch <- t.Value
			walk(t.Right)
		}
	}
	walk(t)
	close(ch)
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	ch1 := make(chan int)
	ch2 := make(chan int)
	go Walk(t1, ch1)
	go Walk(t2, ch2)
	for x := range ch1 {
		if x != <-ch2 {
			return false
		}
	}
	return true
}

func main() {
	ch := make(chan int)
	go Walk(tree.New(1), ch)
	for x := range ch {
		println(x)
	}
	println(tree.New(1).String())
	// t1 := tree.New(1)
	// t2 := tree.New(1)

	println(Same(tree.New(1), tree.New(1)))
	println(Same(tree.New(1), tree.New(2)))

}
