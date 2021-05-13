// lcci17.05
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
    pub fn find_longest_subarray(A: Vec<String>) -> Vec<String> {
        let mut hash = [0usize; 200005];
        let (mut f, mut g, mut pos, mut len) = (0, 0, 0, 0);
        for (i, s) in A.iter().enumerate() {
            let ch = s.chars().next().unwrap();
            if ch.is_digit(10) { f += 1; }
            else { g += 1; }
            let h = &mut hash[f + 100000 - g ];
            if *h == 0 && f != g { *h = i + 1; }
            else if i + 1 - *h > len { pos = *h; len = i + 1 - *h; }
        }
        A[pos..pos+len].to_vec()
    }
}

fn main() {
    // println!("ans = {:?}", Solution::find_longest_subarray(vec_of_strings!["d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"]));
    println!("ans = {:?}", Solution::find_longest_subarray(vec_of_strings!["A", "1"]));
}
