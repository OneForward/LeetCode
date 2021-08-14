// leet1337
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

pub fn lower_bound<T>(v: &Vec<T>, x: &T) -> usize
where T: Ord
{
    let (mut lft, mut rht) = (0, v.len());
    while lft < rht {
        let mid = (lft + rht) / 2;
        if v[mid] <= *x { rht = mid; }
        else { lft = mid + 1; }
    }
    lft
}

impl Solution {
    pub fn k_weakest_rows(M: Vec<Vec<i32>>, K: i32) -> Vec<i32> {
        let mut R: Vec<(usize, usize)> = M.iter().enumerate().map(
            |(r, v)| (lower_bound(v, &0), r)
        ).collect();
        
        R.sort_unstable();
        
        R[..K as usize].iter().map(|(x, r)| *r as i32).collect()
    }
}

fn main() {
    println!("ans = {:?}", Solution::k_weakest_rows(vec2d!
        [[1,1,0,0,0],
        [1,1,1,1,0],
        [1,0,0,0,0],
        [1,1,0,0,0],
        [1,1,1,1,1]], 3));
    println!("ans = {:?}", Solution::k_weakest_rows(vec2d!
        [[1,0,0,0],
        [1,1,1,1],
        [1,0,0,0],
        [1,0,0,0]], 2));
}
