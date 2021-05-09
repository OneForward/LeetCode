// leet1482
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
    pub fn min_days(bloom_day: Vec<i32>, m: i32, k: i32) -> i32 {
        let ok = |day: i32| {
            let (mut cnt, mut total) = (0, 0);
            for &x in bloom_day.iter() {
                if x <= day { cnt += 1; }
                else { cnt = 0; }
                if cnt == k { total += 1; cnt = 0; }
                if total == m { break; }
            }
            total == m
        };
        
        let (mut lft, mut rht) = (0, 0);
        if let Some(&x) = bloom_day.iter().max() { rht = x; }
        while lft < rht {
            let mid = (lft + rht) / 2;
            if ok(mid) { rht = mid; }
            else { lft = mid + 1; }
        }
        if ok(lft) { lft }
        else { -1 }
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_days(vec![1,10,3,10,2], 3, 1));
    println!("ans = {:?}", Solution::min_days(vec![1,10,3,10,2], 3, 2));
    println!("ans = {:?}", Solution::min_days(vec![7,7,7,7,12,7,7], 2, 3));
    println!("ans = {:?}", Solution::min_days(vec![1000000000,1000000000], 1, 1));
    println!("ans = {:?}", Solution::min_days(vec![1,10,2,9,3,8,4,7,5,6], 4, 2));
}
