// leet065
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
    pub fn is_number(s: String) -> bool {
        let f = |ch: char| {
            match ch {
                '+' | '-' => 0,
                '0'..='9' => 1,
                '.' => 2,
                'e' | 'E' => 3,
                _ => 4,
            }
        };
        let trans = [
            [1, 2, 3, 9, 9],
            [9, 2, 3, 9, 9],
            [9, 2, 4, 6, 9],
            [9, 5, 9, 9, 9],
            [9, 5, 9, 6, 9],
            [9, 5, 9, 6, 9],
            [7, 8, 9, 9, 9],
            [9, 8, 9, 9, 9],
            [9, 8, 9, 9, 9],
        ];
        let mut state = 0;
        for ch in s.chars() {
            state = trans[state][f(ch)];
            if state == 9 { break; }
        }
        let ok = [2, 4, 5, 8];
        
        ok.iter().any(|&ch| ch == state )
    }
}

fn main() {
    println!("ans = {:?}", Solution::is_number("0".to_string()));
}
