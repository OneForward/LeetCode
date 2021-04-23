// leet491
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]


macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

macro_rules!vec2d {
    [ $( [ $( $d:expr ),* ] ),* ] => {
        vec![
            $(
                vec![$($d),*],
            )* 
        ]
    }
}

struct Solution;


use std::collections::{HashMap, HashSet};
use std::cmp::{max, min};

impl Solution {
    pub fn find_subsequences(A: Vec<i32>) -> Vec<Vec<i32>> {
        let MOD = 1e9 as i64 + 7;
        let hash = |x: i64, y: i64| { (x * 233 + y + 101) % MOD };
        let mut S = HashSet::new();
        let mut ans:Vec<Vec<i32>> = Vec::new();
        let mut H = Vec::new();
        for i in 1..A.len() {
            for j in 0..ans.len() {
                if let Some(&top) = ans[j].last() {
                    if top <= A[i] {
                        let h = hash(H[j], A[i] as i64);
                        if !S.contains(&h) { 
                            let mut v = ans[j].clone();
                            v.push(A[i]); ans.push(v);
                            S.insert(h); H.push(h);
                        }
                    }
                }
            }
            for j in 0..i {
                if A[j] <= A[i] {
                    let h = hash(A[j] as i64, A[i] as i64);
                    if !S.contains(&h) {
                        ans.push(vec![A[j], A[i]]);
                        S.insert(h); H.push(h);
                    }
                }
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_subsequences(vec![4,6,7,7]));
    println!("ans = {:?}", Solution::find_subsequences(vec![4,4,3,2,1]));
    println!("ans = {:?}", Solution::find_subsequences(vec![-1,0,0,0]));
}
