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
    pub fn nth_super_ugly_number(n: i32, primes: Vec<i32>) -> i32 {
        let K = primes.len();
        let n = n as usize;
        let mut Pos = vec![0; K];
        let mut f = vec![1];
        
        while f.len() < n  {
            let mut x = i64::MAX;
            for k in 0..K {
                x = min(x, f[Pos[k]] * primes[k] as i64);
            }
            f.push(x);
            for k in 0..K {
                if f[Pos[k]] * primes[k] as i64 == x { Pos[k] += 1; }
            }
        }
        f[n-1] as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::nth_super_ugly_number(12, vec![2,7,13,19]));
    println!("ans = {:?}", Solution::nth_super_ugly_number(1, vec![2,3,5]));
}
