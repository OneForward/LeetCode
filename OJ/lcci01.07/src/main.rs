// lcci01.07
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, mem::swap};
use std::cmp::{max, min};



impl Solution {
    pub fn rotate(M: &mut Vec<Vec<i32>>) {
        let N = M.len();
        for i in 0..N/2 {
            for j in 0..N {
                let x = M[i][j];
                M[i][j] = M[N-i-1][j];
                M[N-i-1][j] = x;
            }
        }

        for i in 0..N {
            for j in 0..i {
                let x = M[i][j];
                M[i][j] = M[j][i];
                M[j][i] = x;
            }
        }
    }
}

fn main() {
    // println!("ans = {:?}", Solution::method());
}
