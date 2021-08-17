// leet446
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
    pub fn number_of_arithmetic_slices(A: Vec<i32>) -> i32 {
        let N = A.len();
        let mut f: Vec<HashMap<i64, i32>> = vec![HashMap::new(); N];
        let mut ans = 0;
        for i in 1..N {
            for j in 0..i {
                let d = A[i] as i64 - A[j] as i64;
                if let Some(&mut cnt) = f[j].get_mut(&d) {
                    *f[i].entry(d).or_default() += cnt;
                    ans += cnt;
                }
                *f[i].entry(d).or_default() += 1;
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::number_of_arithmetic_slices(vec![2,4,6,8,10]));
    println!("ans = {:?}", Solution::number_of_arithmetic_slices(vec![7,7,7,7,7]));
}
