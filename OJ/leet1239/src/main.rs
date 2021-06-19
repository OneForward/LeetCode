// leet1239
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
    pub fn max_length(A: Vec<String>) -> i32 {
        let mut ans = 0;
        let N = A.len();
        'bad: for x in 0..1<<N {
            let (mut y, mut len) = (0, 0);
            for i in 0..N {
                if x & (1 << i) > 0 {
                    for ch in A[i].bytes() {
                        if y & (1 << (ch - 'a' as u8)) > 0 { continue 'bad;}
                        y |= 1 << (ch - 'a' as u8); len += 1;
                    }
                }
                ans = max(ans, len);
            }
        }
        ans 
    }
}

fn main() {
    println!("ans = {:?}", Solution::max_length(vec_of_strings!["un","iq","ue"]));
    println!("ans = {:?}", Solution::max_length(vec_of_strings!["cha","r","act","ers"]));
    println!("ans = {:?}", Solution::max_length(vec_of_strings!["abcdefghijklmnopqrstuvwxyz"]));
}
