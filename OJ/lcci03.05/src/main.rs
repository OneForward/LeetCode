// lcci03.05
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

struct SortedStack {
    S1: Vec<i32>,
    S2: Vec<i32>,
    top1: usize,
    top2: usize,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SortedStack {

    fn new() -> Self {
        let (S1, S2, top1, top2) = (vec![0; 5005], vec![0; 5005], 0, 0);
        SortedStack{S1, S2, top1, top2}
    }
    
    fn push(&mut self, x: i32) {
        while self.top1 > 0 && self.S1[self.top1 - 1] < x {
            self.top1 -= 1; self.S2[self.top2] = self.S1[self.top1]; 
            self.top2 += 1;
        }
        self.S1[self.top1] = x; self.top1 += 1;
        while self.top2 > 0 {
            self.top2 -= 1; self.S1[self.top1] = self.S2[self.top2]; 
            self.top1 += 1;
        }
    }
    
    fn pop(&mut self) {
        if self.top1 > 0 { self.top1 -= 1; }
    }
    
    fn peek(&self) -> i32 {
        if self.top1 > 0 { self.S1[self.top1 - 1] } 
        else { -1 }
    }
    
    fn is_empty(&self) -> bool {
        self.top1 == 0
    }
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * let obj = SortedStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.is_empty();
 */

fn main() {
    let mut obj = SortedStack::new();
    obj.push(1);
    obj.pop();
    println!("{:?}", obj.peek());
    println!("{:?}", obj.is_empty());
}
