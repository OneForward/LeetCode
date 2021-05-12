// leet1310
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
    pub fn xor_queries1(A: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let N = A.len();
        let mut f = vec![0; N+1];
        for i in 0..N {
            f[i+1] = f[i] ^ A[i];
        }

        let mut ans = Vec::new(); ans.reserve(queries.len());
        for v in queries {
            let (lft, rht) = (v[0] as usize, v[1] as usize);
            ans.push(f[rht+1] ^ f[lft]);
        }
        ans
    }
}

impl Solution {
    pub fn xor_queries(A: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut f = [0; 30_005];
        let (N, M) = (A.len(), queries.len());
        for i in 0..N {
            f[i+1] = f[i] ^ A[i];
        }

        let mut ans = vec![0; M];
        for (i, v) in queries.iter().enumerate() {
            let (lft, rht) = (v[0] as usize, v[1] as usize);
            ans[i] = f[rht+1] ^ f[lft];
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::xor_queries(vec![1,3,4,8], vec2d![[0,1],[1,2],[0,3],[3,3]]));
    println!("ans = {:?}", Solution::xor_queries(vec![4,8,2,10], vec2d![[2,3],[1,3],[0,0],[0,3]]));
}
