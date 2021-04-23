// leet525
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


use std::{collections::HashMap, vec};
use std::cmp::{max, min};

impl Solution {
    pub fn find_max_length(A: Vec<i32>) -> i32 {
        let mut M = vec![0; 100005];
        let mut f = vec![0; 2];
        let mut ans = 0;
        for i in 0..A.len() {
            f[A[i] as usize] += 1;
            let h = 50000 + f[0] - f[1];
            if M[h] == 0 && f[0] != f[1] { M[h] = i as i32 + 1; }
            ans = max(ans, i as i32 - M[h] + 1);
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_max_length(vec![0,1]));
    println!("ans = {:?}", Solution::find_max_length(vec![0,1,0]));
    println!("ans = {:?}", Solution::find_max_length(vec![0,1,0,1]));
    println!("ans = {:?}", Solution::find_max_length(vec![0,1,1,0]));
    println!("ans = {:?}", Solution::find_max_length(vec![0,1,1]));
    println!("ans = {:?}", Solution::find_max_length(vec![0,1,1,0,1,1,1,0]));
}
