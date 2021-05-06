// lcci17.15
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

impl Solution {
    pub fn longest_word(mut words: Vec<String>) -> String {
        // 32ms, 100% in Time
        let mut H: HashSet<String> = words.iter().cloned().collect();
        words.sort_by(|a, b| {
            if a.len() == b.len() { a.cmp(b) }
            else { b.len().cmp(&a.len()) }
        });

        let mut ans = String::new();
        for word in words.iter() {
            // println!("word = {:?}", word);
            H.remove(word);
            let N = word.len();
            if N == 0 { break; }
            let word = word.as_str();
            let mut f = vec![vec![false; N+1]; N];
            for i in 0..N {
                for j in i..=N {
                    if H.contains(&word[i..j]) { 
                        f[i][j] = true; 
                        for k in 0..i {
                            if f[k][i] { f[k][j] = true; }
                        }
                    }
                }
            }
            if f[0][N] { ans = word.to_string(); break; }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::longest_word(vec_of_strings!["cat","banana","dog","nana","walk","walker","dogwalker"]));
}
