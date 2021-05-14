// lcci10.02
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize, vec};
use std::cmp::{max, min};

impl Solution {
    pub fn group_anagrams(S: Vec<String>) -> Vec<Vec<String>> {
        let mut ans: Vec<Vec<String>> = Vec::new();
        let mut M: HashMap<i64, usize> = HashMap::new();
        let MOD = 1e9 as i64 + 7;
        for s in S {
            let mut f = [0; 26];
            for si in s.bytes() {
                f[si as usize - 'a' as usize] += 1;
            }
            let mut x = 0;
            for &fi in f.iter() {
                x = x * 27 + fi; x %=  MOD;
            }
            if M.contains_key(&x) {
                ans[M[&x]].push(s);
            }
            else {
                M.insert(x, ans.len());
                ans.push(vec![s]);
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::group_anagrams(vec_string!["eat", "tea", "tan", "ate", "nat", "bat"]));
}
