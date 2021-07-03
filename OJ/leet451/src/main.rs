// leet451
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::collections::HashMap;
impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut ans = Vec::new(); ans.reserve(s.len());
        let mut C = HashMap::new();
        for ch in s.chars() {
            let entry = C.entry(ch).or_insert(0usize);
            *entry += 1;
        }
        let mut V : Vec<(usize, char)> = C.into_iter().map(|(k, v)| (v, k) ).collect();
        V.sort_unstable();

        for (v, k) in V.into_iter().rev() {
            ans.append(&mut vec![k; v]);
        }
        ans.into_iter().collect()
    }
}

fn main() {
    println!("ans = {:?}", Solution::frequency_sort("tree".to_string()));
    println!("ans = {:?}", Solution::frequency_sort("cccaaa".to_string()));
    println!("ans = {:?}", Solution::frequency_sort("Aabb".to_string()));
}
