// leet912
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
    pub fn sort_array(mut A: Vec<i32>) -> Vec<i32> {
        // 计数排序
        if A.len() > 3000 {
            let mut f = vec![0; 100005];
            let mut B = Vec::new(); 
            B.reserve(A.len());
            for x in A {
                f[(x + 50000)as usize] += 1;
            }
            for (x, cnt) in f.into_iter().enumerate() {
                for _ in 0..cnt { B.push(x as i32 - 50000 ); } 
            }
            B
        }
        else {
            A.sort_unstable();
            A
        }
    }
}

fn main() {
    println!("ans = {:?}", Solution::sort_array(vec![5,1,1,2,0,0]));
}
