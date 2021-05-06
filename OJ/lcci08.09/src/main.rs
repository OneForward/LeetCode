// lcci08.09
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
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        fn f(s: String, lft: i32, rht: i32, n: i32, mut ans: Vec<String>) -> Vec<String> {
            if lft > n || lft < rht { return ans; }
            if lft == n && rht == n {
                ans.push(s.clone());
                return ans;
            }
            ans = f(s.clone() + "(", lft + 1, rht, n, ans);
            ans = f(s.clone() + ")", lft, rht + 1, n, ans);
            ans
        }
        f(String::new(), 0, 0, n, vec![])
    }
}
fn main() {
    println!("ans = {:?}", Solution::generate_parenthesis(4));
    println!("ans = {:?}", Solution::generate_parenthesis(3));
    println!("ans = {:?}", Solution::generate_parenthesis(2));
    println!("ans = {:?}", Solution::generate_parenthesis(1));
}
