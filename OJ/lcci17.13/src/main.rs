// lcci17.13
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


fn hash(s: &String) -> i64 {
    let MOD = 1e9 as i64 + 7;
    let mut x = 0;
    for &ch in s.as_bytes().iter().rev() {
        x = x * 133 + ch as i64; x %= MOD;
    }
    x
}
impl Solution {
    pub fn respace(dictionary: Vec<String>, s: String) -> i32 {
        let mut f = [0; 1005];
        let MOD = 1e9 as i64 + 7;
        let (N, mut ans) = (s.len(), 0);
        let S : HashSet<i64> = dictionary.iter().map(|s| hash(s)).collect();
        let s = s.into_bytes();
        for i in 0..N {
            f[i+1] = f[i];
            let mut x = 0;
            for j in (0..=i).rev() {
                x = x * 133 + s[j] as i64; x %= MOD;
                if S.contains(&x) {
                    f[i + 1] = max(f[i + 1] ,  f[j] + i - j + 1 );
                }
            }
            ans = max(ans, f[i + 1]);
        }
        (N - ans) as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::respace(vec_of_strings!["looked","just","like","her","brother"], "jesslookedjustliketimherbrother".to_string()));
}
