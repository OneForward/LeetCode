// lcci17.08
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
    pub fn best_seq_at_index(height: Vec<i32>, weight: Vec<i32>) -> i32 {
     fn lower_bound(v: &Vec<usize>, weight: &Vec<i32>, x: &usize) -> usize
        {
            let (mut lft, mut rht) = (0, v.len());
            while lft < rht {
                let mid = (lft + rht) / 2;
                if weight[v[mid]] >= weight[*x] { rht = mid; }
                else { lft = mid + 1; }
            }
            lft
        }

        let N = height.len();
        let mut I: Vec<usize> = (0..N).collect();
        I.sort_unstable_by_key(|&i| (height[i], -weight[i]) ); 
        let mut v = Vec::new();
        for x in I {
            let pos = lower_bound(&v, &weight, &x);
            if pos == v.len() { v.push(x); }
            else { v[pos] = x; }
        }
        v.len() as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::best_seq_at_index(vec![7993,4630,2152,7609,6012,5878,4325,3955,4326,1883], vec![3793,8079,8452,1378,4102,3204,6633,4417,1374,7015]));
}
