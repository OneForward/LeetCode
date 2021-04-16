// lcp09
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::{collections::HashMap, usize, vec};

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

use std::cmp::min;
impl Solution {
    pub fn min_jump(A: Vec<i32>) -> i32 {
        let n =  A.len();
        let mut f = vec![i32::MAX; n+1]; f[0] = 0;
        for i in 0..n {
            let rht = min(i+A[i] as usize, n);
            for j in i+1..rht {
                f[j] = min(f[j], f[i]+2);
            }
            f[rht] = min(f[rht], f[i]+1);
        }
        f[n]
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_jump(vec![2, 5, 1, 1, 1, 1]));
}
