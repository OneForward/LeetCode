// leet401
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
use std::fmt::format;

impl Solution {
    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        let mut f = vec![0; 60];
        let mut ans = Vec::new();
        for x in 1..60 {
            f[x] = f[x & (x - 1)] + 1;
        }
        for hour in 0..12 {
            for minute in 0..60 {
                if f[hour] + f[minute] == turned_on {
                    ans.push( format!("{}:{:02}", hour, minute).to_string() );
                }
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::read_binary_watch(0));
    println!("ans = {:?}", Solution::read_binary_watch(1));
    println!("ans = {:?}", Solution::read_binary_watch(9));
    println!("ans = {:?}", Solution::read_binary_watch(10));
    // for turned_on in 0..=10 {
    //     println!("ans = {:?}", Solution::read_binary_watch(turned_on));
    // }
}
