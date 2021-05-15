// lcci16.20
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
    pub fn get_valid_t9_words(num: String, words: Vec<String>) -> Vec<String> {
        let f = ['2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'];
        
        let mut ans = Vec::new();
        let num: Vec<char> = num.chars().collect();
        for word in words {
            let mut ok = true;
            for (i, ch) in word.chars().enumerate() {
                if f[ch as usize - 'a' as usize] != num[i] { ok = false; break; }
            }
            if ok { ans.push(word); }
        }
        
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::get_valid_t9_words("8733".to_string(), vec_string!["tree", "used"]));
    println!("ans = {:?}", Solution::get_valid_t9_words("2".to_string(), vec_string!["a", "b", "c", "d"]));
}
