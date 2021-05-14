// lcci17.11
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
    pub fn find_closest(words: Vec<String>, word1: String, word2: String) -> i32 {
        let mut M = HashMap::new();
        let N = words.len();
        let mut next = vec![0; N];
        for i in (0..N).rev() {
            let s = &words[i];
            if M.contains_key(s) { next[i] = M[s]; }
            else { next[i] = i; }
            M.insert(s, i);
        }

        let (mut i1, mut i2) = (M[&word1], M[&word2]);
        let mut ans = (i1 as i32 - i2 as i32).abs();
        while i1 != next[i1] && i2 != next[i2] {
            if i1 < i2 { i1 = next[i1]; }
            else { i2 = next[i2]; }
            ans = min((i1 as i32 - i2 as i32).abs(), ans);
        }
        while i1 != next[i1] && i1 < i2 {
            i1 = next[i1]; 
            ans = min((i1 as i32 - i2 as i32).abs(), ans);
        }
        while i2 != next[i2] && i2 < i1 {
            i2 = next[i2]; 
            ans = min((i1 as i32 - i2 as i32).abs(), ans);
        }
        
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_closest(vec_string!["I","am","a","student","from","a","university","in","a","city"],  "a".to_string(),  "student".to_string()));
}
