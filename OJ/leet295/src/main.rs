// leet295
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::collections::*;
use std::cmp::{max, min};

struct MedianFinder {
    min_q: BinaryHeap<i32>,
    max_q: BinaryHeap<i32>,
}


impl MedianFinder {

    /** initialize your data structure here. */
    fn new() -> Self {
        MedianFinder {
            min_q: BinaryHeap::new(),
            max_q: BinaryHeap::new(),
        }
    }
    
    fn add_num(&mut self, x: i32) {
        let n = self.max_q.len();
        let m = self.min_q.len();
        if n == m {
            if m > 0 && x >= -*self.min_q.peek().unwrap() {
                self.min_q.push(-x);
            }
            else { self.max_q.push(x) }
        }
        else if n > m {
            if x >= *self.max_q.peek().unwrap() { self.min_q.push(-x)}
            else {
                self.max_q.push(x);
                self.min_q.push(-self.max_q.pop().unwrap());
            }
        }
        else {
            if x <= -*self.min_q.peek().unwrap() { self.max_q.push(x)}
            else {
                self.min_q.push(-x);
                self.max_q.push(-self.min_q.pop().unwrap());
            }
        }
    }
    
    fn find_median(&self) -> f64 {
        let n = self.max_q.len();
        let m = self.min_q.len();
        if n > m { *self.max_q.peek().unwrap() as f64 }
        else if n < m { -*self.min_q.peek().unwrap() as f64 }
        else { (*self.max_q.peek().unwrap() as f64 -  *self.min_q.peek().unwrap() as f64) / 2.}
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder::new();
 * obj.add_num(num);
 * let ret_2: f64 = obj.find_median();
 */

fn main() {
    let mut sol = MedianFinder::new();
    sol.add_num(1);
    sol.add_num(2);
    dbg!(sol.find_median());
    sol.add_num(3);
    dbg!(sol.find_median());
}
