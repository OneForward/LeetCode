// leet498
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
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let (R, C) = (mat.len(), mat[0].len());
        let mut v = Vec::new(); v.reserve(R * C);
        for f in 0..(R+C-1) {
            let clft = max(0, f as i32 + 1 - R as i32) as usize;
            let crht = min(f, C - 1);
            if f % 2 == 0 {
                for c in clft..=crht { v.push( mat[f-c][c] ) }
            }
            else {
                for c in (clft..=crht).rev() { v.push( mat[f-c][c] ) }
            }
        }
        v 
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_diagonal_order(vec2d![[1,2,3],[4,5,6],[7,8,9]]));
    println!("ans = {:?}", Solution::find_diagonal_order(vec2d![[1,2],[3,4]]));
}
