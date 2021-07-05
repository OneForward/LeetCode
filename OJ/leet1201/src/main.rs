// leet1201
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

pub fn gcd (x: i64, y : i64) -> i64 {
    if y == 0 { x }
    else {
        gcd(y, x % y)
    }
}

impl Solution {
    pub fn nth_ugly_number(n: i32, a: i32, b: i32, c: i32) -> i32 {
        let (a, b, c, n) = (a as i64, b as i64, c as i64, n as i64);
        let ab = a * b / gcd(a, b);
        let ac = a * c / gcd(a, c);
        let cb = c * b / gcd(c, b);
        let abc = ab * ac / gcd(ab, ac);

        let f = |n: i64| -> i64 {
            n / a + n / b + n / c - n / ab - n / ac - n / cb + n / abc
        };
        
        let (mut lft, mut rht) = (0, i32::MAX);
        while lft < rht {
            let mid = lft + (rht - lft) / 2;
            if f(mid as i64) >= n { rht = mid; }
            else { lft = mid + 1; }
        }
        lft
    }
}

fn main() {
    println!("ans = {:?}", Solution::nth_ugly_number(7, 7, 7, 7));
    println!("ans = {:?}", Solution::nth_ugly_number(5, 2, 3, 3));
    println!("ans = {:?}", Solution::nth_ugly_number(3, 2, 3, 5));
    println!("ans = {:?}", Solution::nth_ugly_number(4, 2, 3, 4));
    println!("ans = {:?}", Solution::nth_ugly_number(5, 2, 11, 13));
    println!("ans = {:?}", Solution::nth_ugly_number(1000000000,  2,  217983653,  336916467));
}
