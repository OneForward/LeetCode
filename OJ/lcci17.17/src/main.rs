// lcci17.17
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, vec};
use std::cmp::{max, min};

impl Solution {
    pub fn multi_search(big: String, smalls: Vec<String>) -> Vec<Vec<i32>> {
        // 100% 100%  字符串哈希
        let big = big.into_bytes();
        let N = big.len();
        let mut f = vec![vec![0; 1005]; 1005];
        let MOD = 1e9 as i64 + 7;
        for i in 0..N {
            let mut hash = 0;
            for j in i..N {
                hash = (hash * 133 + big[j] as i64 - 'a' as i64 + 1) % MOD;
                f[i][j+1] = hash;
            }
        }
        
        let mut ans = vec![vec![]; smalls.len()];
        for (i, s) in smalls.into_iter().enumerate() {
            let len = s.len();
            if len == 0 || len > N { continue; }
            let mut hash = 0;
            for ch in s.into_bytes() {
                hash = (hash * 133 + ch as i64 - 'a' as i64 + 1) % MOD;
            }
            for j in 0..=N-len {
                if f[j][j+len] == hash { ans[i].push(j as i32); }
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::multi_search("mississippi".to_string(), vec_of_strings!["is","ppi","hi","sis","i","ssippi"]));
    println!("ans = {:?}", Solution::multi_search("".to_string(), vec_of_strings!["is","a","b","","i","c"]));
}
