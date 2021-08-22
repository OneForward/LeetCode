// leet789
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
    pub fn escape_ghosts(ghosts: Vec<Vec<i32>>, target: Vec<i32>) -> bool {
        let mut ok = true;
        let (xt, yt) = (target[0], target[1]);
        let d0 = (xt).abs() + (yt).abs();
        for point in ghosts {
            let (x0, y0) = (point[0], point[1]);
            let d1 = (xt - x0).abs() + (yt - y0).abs();
            if d1 <= d0  {
                ok = false; break;
            }
        }
        ok
    }
}

fn main() {
    println!("ans = {:?}", Solution::escape_ghosts(vec2d![[1,8],[-9,0],[-7,-6],[4,3],[1,3]], vec![6,-9]));
    println!("ans = {:?}", Solution::escape_ghosts(vec2d![[2,2]], vec![1,1]));
    println!("ans = {:?}", Solution::escape_ghosts(vec2d![[1,0],[0,3]], vec![0,1]));
    println!("ans = {:?}", Solution::escape_ghosts(vec2d![[1,0]], vec![2,0]));
    println!("ans = {:?}", Solution::escape_ghosts(vec2d![[2,0]], vec![1,0]));
}
