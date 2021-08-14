// leet313
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
impl Solution {
    pub fn nth_super_ugly_number(N: i32, primes: Vec<i32>) -> i32 {
        // O(N log K)
        let K = primes.len();
        let N = N as usize;
        let mut f = vec![-1]; f.reserve(N);
        let mut Q = BinaryHeap::new();
        for &x in primes.iter() { Q.push((-x, 0, x)); }
        for _ in 1..N  {
            let (x, idx, p) = Q.pop().unwrap(); 
            f.push(x);
            Q.push((p * f[idx + 1], idx + 1, p ));
            loop {
                let mut val = Q.peek_mut().unwrap(); 
                let (xtop, idx, p) = *val;
                if  xtop == x {  
                    *val = (p * f[idx + 1], idx + 1, p );
                }
                else { break;}
            }
        }
        -f[N-1] as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::nth_super_ugly_number(12, vec![2,7,13,19]));
    println!("ans = {:?}", Solution::nth_super_ugly_number(1, vec![2,3,5]));
    println!("ans = {:?}", Solution::nth_super_ugly_number(15, vec![3,5,7,11,19,23,29,41,43,47]));
}
