// leet862
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
    pub fn shortest_subarray(A: Vec<i32>, target: i32) -> i32 {
        let mut f = vec![0; 50005];
        for i in 0..A.len() {
            f[i + 1] = f[i] + A[i];
        }
        let MAX = usize::MAX;
        let mut ans = MAX;
        let mut Q = VecDeque::new();
        for i in 0..=A.len() {
            let mut head = MAX;
            while !Q.is_empty() && f[Q[Q.len() - 1]] >= f[i] { Q.pop_back(); }
            while !Q.is_empty() && f[Q[0]] <= f[i] - target { head = Q[0]; Q.pop_front(); }
            Q.push_back(i);
            if head < A.len() { ans = min(ans, i - head)};
        }
        if ans == MAX { -1 }
        else { ans as i32}
    }
}

fn main() {
    println!("ans = {:?}", Solution::shortest_subarray(vec![1], 1));
}
