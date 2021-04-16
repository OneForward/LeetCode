// leet008
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::collections::HashMap;

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        // 0ms, leet008
        let s: Vec<char> = s.chars().collect();
        
        let mut len = s.len(); let mut st = len;
        for i in 0..len {
            if s[i] != ' '  { st = i; break; }
        }
        if st == len { return 0; }

        let mut sign = 1;
        match s[st] {
            '0'..='9' => {},
            '+' => { st += 1; },
            '-' => { st += 1; sign = -1; },
            _ => { return 0; }
        }

        let mut ans = 0i64;
        for i in st..len {
            if s[i].is_digit(10) { break; }
            ans = ans * 10 + s[i] as i64 - '0' as i64;
            if ans > i32::MAX as i64 {
                if sign > 0 { return i32::MAX; }
                else { return i32::MIN; }
            }
        } 
        sign * ans as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::method());
}
