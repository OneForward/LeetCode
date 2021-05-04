// leet1473
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
    pub fn min_cost(houses: Vec<i32>, cost: Vec<Vec<i32>>, M: i32, C: i32, T: i32) -> i32 {
        // 20ms, 3.2MB, both 100%
        let (MAX, M, C, T) = (i32::MAX / 2, M as usize, C as usize, T as usize);
        let mut f = vec![vec![vec![MAX; C]; T+1]; M+1];
        for c in 0..C { f[0][0][c] = 0; }
        for m in 1..=M {
            if houses[m-1] > 0 {
                let c = (houses[m-1] - 1) as usize;
                for t in 1..=T {
                    let mut v = f[m-1][t][c];
                    for x in 0..C {
                        if c == x { continue; }
                        v = min(v, f[m-1][t-1][x])
                    }
                    f[m][t][c] = v;
                }
                continue;
            }
            
            for t in 1..=T {
                for c in 0..C {
                    let mut v = f[m-1][t][c];
                    for x in 0..C {
                        if c == x { continue; }
                        v = min(v, f[m-1][t-1][x])
                    }
                    f[m][t][c] = v + cost[m-1][c];
                }
            }
        }
        if let Some(&ans) = f[M][T].iter().min() {
            if ans >= MAX { -1 }
            else { ans }
        }
        else {-1}
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_cost(  vec![0,0,0,0,0], vec2d![[1,10],[10,1],[10,1],[1,10],[5,1]], 5, 2, 3 ));
    println!("ans = {:?}", Solution::min_cost(  vec![0,2,1,2,0], vec2d![[1,10],[10,1],[10,1],[1,10],[5,1]], 5, 2, 3 ));
    println!("ans = {:?}", Solution::min_cost(  vec![0,0,0,0,0], vec2d![[1,10],[10,1],[1,10],[10,1],[1,10]], 5, 2, 5 ));
    println!("ans = {:?}", Solution::min_cost(  vec![3,1,2,3], vec2d![[1,1,1],[1,1,1],[1,1,1],[1,1,1]], 4, 3, 3 ));
}
