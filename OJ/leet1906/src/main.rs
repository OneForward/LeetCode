// leet1906
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{clone, collections::*, usize};
use std::cmp::{max, min};

impl Solution {
    pub fn min_difference(A: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        //  前缀和法 Time: O(R N + R Q), R = 100
        // Space O(R N)
        let mut ans = Vec::new(); ans.reserve(queries.len());
        let mut f = vec![[0; 101]; A.len() + 1];
        
        for (i, &x) in A.iter().enumerate() {
            f.copy_within(i..i+1, i+1);
            f[i + 1][x as usize] += 1;
        }
        for q in queries {
            let (lft, rht) = (q[0]  as usize, q[1] as usize + 1);
            let (mut prev, mut minans) = (0, 100);
            for i in 1..=100 {
                let p1 = f[lft][i];
                let p2 = f[rht][i];
                if p2 > p1 { 
                    if prev != 0 { minans = min(minans, i - prev); } 
                    prev = i; 
                }
                if minans == 1 { break; }
            }
            if minans == 100 { ans.push(-1); }
            else { ans.push(minans as i32); }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_difference(vec![1,3,4,8], vec2d! [[0,1],[1,2],[2,3],[0,3]]));
    println!("ans = {:?}", Solution::min_difference(vec![4,5,2,2,7,10], vec2d![[2,3],[0,2],[0,5],[3,5]]));
}
