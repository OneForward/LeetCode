package main

import "time"

func main() {
	tick := time.Tick(100 * time.Millisecond)
	boom := time.After(500 * time.Millisecond)
	for {
		select {
		case <-tick:
			println("tick.")
		case <-boom:
			println("Boom!")
			return
		default:
			println("    .")
			time.Sleep((50 * time.Millisecond))
		}
	}
}
