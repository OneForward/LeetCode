// leet668
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

// 3 3
// 1 2 3
// 2 4 6
// 3 6 9
pub fn search(M: i32, N: i32, x: i32) -> i32 {
    let (mut r, mut c, mut cnt) = (M, 1, 0);
    while r >= 1 && c <= N {
        if r * c > x  { r -= 1; cnt += c - 1; }
        else { c += 1; }
    }
    cnt += r * (c - 1);
    // println!("{}, {}, {:?} = {}", M, N, x, cnt);
    cnt
}


impl Solution {
    pub fn find_kth_number(m: i32, n: i32, k: i32) -> i32 {
        // O( (M+N) * log (MN)  ) = 3e4 * 32
        let (mut lft, mut rht) = (1, m * n + 1);
        while lft < rht {
            let x = lft + (rht - lft) / 2;
            if search(m, n, x) >= k { rht = x; }
            else { lft = x + 1; }
        }
        lft 
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_kth_number(3, 1, 3));
    println!("ans = {:?}", Solution::find_kth_number(3, 3, 5));
    println!("ans = {:?}", Solution::find_kth_number(2, 3, 6));
}
