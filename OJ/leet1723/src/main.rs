// leet1723
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize};
use std::cmp::{max, min};

impl Solution {
    pub fn minimum_time_required(jobs: Vec<i32>, K: i32) -> i32 {
        // 动态规划
        let mut A = [0; 1<<12];
        let N = jobs.len();
        for i in 0..N {
            A[1<<i] = jobs[i];
        }
        
        for x in 0i32..1<<N  {
            A[x as usize] = A[(x & (x - 1)) as usize] + A[(x & -x) as usize];
        }
        
        let mut f = [i32::MAX; 1<<12];
        let mut g = A.clone();
        for k in 1..K {
            for x in 0..1<<N {
                let mut y = x;
                while y > 0 {
                    f[x] = min(f[x], max(A[y], g[x ^ y]));
                    y = (y - 1 ) & x;
                }
            }
            g.copy_from_slice(&f);
            f = [i32::MAX; 1<<12];
        }
        g[(1<<N) - 1]
    }
}

fn main() {
    println!("ans = {:?}", Solution::minimum_time_required(vec![3,2,3], 3));
    println!("ans = {:?}", Solution::minimum_time_required(vec![1,2,4,7,8], 2));
}
