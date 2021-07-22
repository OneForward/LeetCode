// leet649
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
    pub fn predict_party_victory(senate: String) -> String {
        let N = senate.len();
        let mut R = VecDeque::new();
        let mut D = VecDeque::new();
        for (i, x) in senate.bytes().enumerate() {
            if x == 'R' as u8 { R.push_back(i) }
            else { D.push_back(i) }
        }
        
        while !R.is_empty() && !D.is_empty() {
            if R.front() < D.front() { R.push_back(R.front().unwrap() + N ); }
            else { D.push_back(D.front().unwrap() + N ); }
            R.pop_front();
            D.pop_front();
        }
        
        if D.is_empty() { "Radiant".to_string() }
        else  { "Dire".to_string() }
    }
}

fn main() {
    println!("ans = {:?}", Solution::predict_party_victory("RD".to_string()));
    println!("ans = {:?}", Solution::predict_party_victory("RDDR".to_string()));
    println!("ans = {:?}", Solution::predict_party_victory("DDRRR".to_string()));
    println!("ans = {:?}", Solution::predict_party_victory("RRDDD".to_string()));
    println!("ans = {:?}", Solution::predict_party_victory("RDD".to_string()));
    println!("ans = {:?}", Solution::predict_party_victory("DRRDRDRDRDDRDRDR".to_string()));
}
