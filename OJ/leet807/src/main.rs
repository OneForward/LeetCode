// leet807
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
    pub fn max_increase_keeping_skyline(grid: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let (R, C) = (grid.len(), grid[0].len());
        let mut row = vec![0; C];
        let mut col = vec![0; R];
        for r in 0..R {
            for c in 0..C {
                row[c] = max(row[c], grid[r][c]);
                col[r] = max(col[r], grid[r][c]);
            }
        }
        for r in 0..R {
            for c in 0..C {
                ans += min(row[c], col[r]) - grid[r][c];
            }
        }

        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::max_increase_keeping_skyline(vec2d![[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]));
}
