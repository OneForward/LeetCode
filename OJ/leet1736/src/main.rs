// leet1736
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
    pub fn maximum_time(time: String) -> String {
        let time = time.as_bytes();
        let ok = |H: i32, M: i32| {
            let s = format!("{:02}:{:02}", H, M);
            let s = s.as_bytes();
            let mut ok=  true;
            for i in 0..5 {
                if s[i] != time[i] && time[i] != '?' as u8 { ok = false; break; }
            }
            ok 
        };

        let (mut H, mut M) = (0, 0);
        for hour in 0..24 {
            for minute in 0..60 {
                if ok(hour, minute)  { H = hour; M = minute;}
            }
        }
        format!("{:02}:{:02}", H, M)
    }
}

fn main() {
    println!("ans = {:?}", Solution::maximum_time("2?:?0".to_string()));
}
