// leet1074
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
    pub fn num_submatrix_sum_target(M: Vec<Vec<i32>>, target: i32) -> i32 {
        let (R, C) = (M.len(), M[0].len());
        let mut ans = 0;
        for r1 in 0..R {
            let mut colSum = vec![0; C];
            for r2 in r1..R {
                for c in 0..C {
                    colSum[c] += M[r2][c];
                }
                for c1 in 0..C {
                    let mut sum = 0;
                    for c2 in c1..C {
                        sum += colSum[c2];
                        if sum == target { ans += 1; }
                    }
                }
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::num_submatrix_sum_target(vec2d![[0,1,0],[1,1,1],[0,1,0]], 0));
    println!("ans = {:?}", Solution::num_submatrix_sum_target(vec2d![[1,-1],[-1,1]], 0));
}
