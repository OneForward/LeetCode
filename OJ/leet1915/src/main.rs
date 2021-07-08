// leet1915
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
    pub fn wonderful_substrings(word: String) -> i64 {
        let mut ans = 0;

        let mut f = vec![0; 10];
        let mut M = vec![0; 1<<10];
        M[0] = 1;

        for ch in word.chars() {
            f[ch as usize - 'a' as usize] += 1;
            
            let mut m = 0;
            for (i, fi) in f.iter().enumerate() {
                if fi % 2 == 1 { m |= 1 << i; }
            }
            ans += M[m];   M[m] += 1;
            
            for i in 0..10 {
                ans += M[m ^ (1 << i)];
            }
        }

        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::wonderful_substrings("aba".to_string()));
    println!("ans = {:?}", Solution::wonderful_substrings("aabb".to_string()));
    println!("ans = {:?}", Solution::wonderful_substrings("he".to_string()));
}
