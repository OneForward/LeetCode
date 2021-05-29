// leet1345
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
    pub fn min_jumps(A: Vec<i32>) -> i32 {
        let N = A.len();
        let mut M: HashMap<i32, usize> = HashMap::new();
        let mut ans = 0;
        let (mut f, mut visited) = (vec![N; N], vec![false; N]);
        for i in 0..N {
            let x = &A[i];
            if M.contains_key(x) { f[i] = M[x]; }
            M.insert(*x, i);
        }
        let mut Q = VecDeque::new(); 
        if A.len() > 1 { Q.push_back(0); }
        'outer: while ! Q.is_empty() {
            ans += 1;
            for _ in 0..Q.len() {
                if let Some(i) = Q.pop_front() {
                    let p = i + 1;
                    if p == N - 1 { break 'outer; }
                    if p < N && ! visited[p] { visited[p] = true; Q.push_back(p); }
                    if i > 0 {
                        let p = i - 1;
                        if ! visited[p] { visited[p] = true; Q.push_back(p); }
                    }
                    
                    let mut p = M[&A[i]];
                    while p != N {
                        if p == N - 1 { break 'outer; }
                        if ! visited[p] { visited[p] = true; Q.push_back(p); }
                        p = f[p];
                    }
                    M.insert(A[i], N);
                }
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_jumps(vec![100,-23,-23,404,100,23,23,23,3,404]));
    println!("ans = {:?}", Solution::min_jumps(vec![7,6,9,6,9,6,9,7]));
    println!("ans = {:?}", Solution::min_jumps(vec![7]));
    println!("ans = {:?}", Solution::min_jumps(vec![6,1,9]));
    println!("ans = {:?}", Solution::min_jumps(vec![11,22,7,7,7,7,7,7,7,22,13]));
}
