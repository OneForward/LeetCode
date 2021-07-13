// leet1818
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
        if v[mid] >= *x { rht = mid; }
        else { lft = mid + 1; }
    }
    lft
}

impl Solution {
    pub fn min_absolute_sum_diff(mut A: Vec<i32>, B: Vec<i32>) -> i32 {
        let MOD = 1_000_000_007;
        let N = A.len();
        let mut ans = 0;
        let mut delta = 0;
        let mut D = vec![0; N];
        for i in 0..N {
            let x = (A[i] - B[i]).abs(); D[i] = x;
            ans += x as i64; 
        }

        A.sort_unstable();

        for i in 0..N {
            let pos = lower_bound(&A, &B[i]);
            if pos < N { delta = max(delta, D[i] - (A[pos] - B[i]).abs() )}
            if pos >= 1 { delta = max(delta, D[i] - (A[pos-1] - B[i]).abs() ) }
        }

        ((ans - delta as i64) % MOD) as i32 
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_absolute_sum_diff(vec![1,7,5], vec![2,3,5]));
    println!("ans = {:?}", Solution::min_absolute_sum_diff(vec![1,10,4,4,2,7], vec![9,3,5,1,7,4]));
}
