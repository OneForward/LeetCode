// leet526
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
    pub fn count_arrangement(n: i32) -> i32 {
        let n = n as usize;
        let mut f = vec![0; 1 << n];
        for i in 0..n {
            f[1 << i] = 1;
        }

        for x in 1..1<<n {
            let cnt = (x as u32).count_ones() as usize + 1;
            for j in 1..=n {
                if x & (1 << (j-1)) !=0 || (j % cnt != 0 && cnt % j != 0) { continue; }
                f[x | 1 << (j-1) ] += f[x];
            }
        }


        *f.last().unwrap()
    }
}

fn main() {
    println!("ans = {:?}", Solution::count_arrangement(2));
    println!("ans = {:?}", Solution::count_arrangement(3));
}
