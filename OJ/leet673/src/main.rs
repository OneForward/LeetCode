// leet673
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

impl Solution {
    pub fn find_number_of_lis(A: Vec<i32>) -> i32 {
        let N = A.len();
        let mut cnt = vec![1; N];
        let mut len = vec![0; N];
        
        for i in 0..N {
            for j in 0..i {
                if A[i] <= A[j] { continue; }
                if len[i] == len[j] + 1 { 
                    cnt[i] += cnt[j]; 
                }
                else if len[i] < len[j] + 1  {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
        }
        
        let maxlen = len.iter().max().unwrap();

        let mut ans = 0;

        for (lenx, cntx) in len.iter().zip(cnt.iter()) {
            if lenx == maxlen { ans += cntx }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_number_of_lis(vec![1,3,5,4,7]));
    println!("ans = {:?}", Solution::find_number_of_lis(vec![2,2,2,2,2,]));
}
