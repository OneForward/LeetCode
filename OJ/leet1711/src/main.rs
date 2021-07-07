// leet1711
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
    pub fn count_pairs(deliciousness: Vec<i32>) -> i32 {
        let MOD = 1e9 as i32 + 7;
        let mut Counter = HashMap::new();
        for x in deliciousness.iter() {
            *Counter.entry(x).or_insert(0) += 1;
        }
        let mut ans = 0;
        for (&&x, &cnt) in Counter.iter() {
            for i in 0..=21 {
                let y = (1 << i) - x;
                if let Some(cnt2) = Counter.get(&y) {
                    if x == y { ans += (cnt as i64 * (cnt - 1) as i64 / 2  % MOD as i64) as i32; }
                    else if x > y { ans += cnt * cnt2; }
                    ans %= MOD;
                }
            }
        }
        ans 
    }
}

fn main() {
    println!("ans = {:?}", Solution::count_pairs(vec![1,3,5,7,9]));
    println!("ans = {:?}", Solution::count_pairs(vec![1,1,1,3,3,3,7]));
    println!("ans = {:?}", Solution::count_pairs(vec![1048576,1048576]));
}
