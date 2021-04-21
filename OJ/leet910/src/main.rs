// leet910
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;


macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

use std::collections::HashMap;
use std::cmp::{max, min};

impl Solution {
    pub fn smallest_range_ii(mut A: Vec<i32>, K: i32) -> i32 {
        A.sort_unstable();
        let N = A.len();
        let mut ans = A[N-1] - A[0];
        for i in 0..N-1 {
            let hi = max(A[N-1], A[i] + 2 * K);
            let lo = min(A[0] + 2 * K, A[i+1]);
            ans = min(ans, hi - lo);
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::smallest_range_ii(vec![1], 0));
    println!("ans = {:?}", Solution::smallest_range_ii(vec![0, 10], 2));
    println!("ans = {:?}", Solution::smallest_range_ii(vec![1,3,6], 3));
}
