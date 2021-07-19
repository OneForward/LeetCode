// leet1838
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize, vec};
use std::cmp::{max, min};

fn isok(A: &Vec<i64>, S: &Vec<i64>, cnt: usize, k: i64) -> bool {
    let mut ok = false;

    for r in (cnt-1)..A.len() {
        if (cnt - 1) as i64 * A[r] - (S[r] - S[r + 1 - cnt] ) <= k  { ok = true; break; }
    }
    ok
}

impl Solution {
    pub fn max_frequency(mut A: Vec<i32>, k: i32) -> i32 {
        A.sort_unstable();
        let A: Vec<i64> = A.iter().map(|&x| x as i64).collect();
        let N = A.len();
        let mut S = vec![0; N+1];
        for i in 0..N {
            S[i+1] = S[i] + A[i];
        }
        let k = k as i64;

        let (mut lft, mut rht) = (1, A.len() + 1);
        while lft < rht {
            let cnt = (lft + rht) / 2;
            if ! isok(&A, &S, cnt, k) { rht = cnt; }
            else { lft = cnt + 1; }
        }
        lft as i32 - 1
    }
}

fn main() {
    println!("ans = {:?}", Solution::max_frequency(vec![1,2,4],  5));
    println!("ans = {:?}", Solution::max_frequency(vec![1,4,8,13],  5));
    println!("ans = {:?}", Solution::max_frequency(vec![3,9,6],  2));
    println!("ans = {:?}", Solution::max_frequency(vec![9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966]
        ,3056));
}
