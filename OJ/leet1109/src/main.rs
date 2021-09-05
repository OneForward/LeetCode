// leet1109
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
    pub fn corp_flight_bookings(bookings: Vec<Vec<i32>>, n: i32) -> Vec<i32> {
        let n = n as usize;
        let mut d = vec![0; n+2];
        for v in bookings {
            let (lft, rht, dx) = (v[0] as usize, v[1] as usize, v[2]);
            d[lft] += dx; d[rht+1] -= dx;
        }
        for i in 0..n {
            d[i+1] += d[i];
        }
        d[1..n+1].to_vec()
    }
}

fn main() {
    println!("ans = {:?}", Solution::corp_flight_bookings(vec2d![[1,2,10],[2,3,20],[2,5,25]], 5));
    println!("ans = {:?}", Solution::corp_flight_bookings(vec2d![[1,2,10],[2,2,15]], 2));
}
