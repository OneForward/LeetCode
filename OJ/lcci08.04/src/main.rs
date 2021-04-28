// lcci08.04
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
    pub fn subsets(mut A: Vec<i32>) -> Vec<Vec<i32>> {
        let N = A.len();
        let mut ans = vec![vec![]];
        let mut lft = 0;
        A.sort();
        
        while lft < N {
            let x = A[lft];
            let mut rht = lft + 1;
            while rht < N && A[rht] == A[rht-1] { rht += 1; }
            let no = ans.to_vec();
            for mut v in no {
                for _ in lft..rht {
                    v.push(x);
                    ans.push(v.clone());
                }
            }

            lft = rht;
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::subsets(vec![1,2,3,3]));
}
