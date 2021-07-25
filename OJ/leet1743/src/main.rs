// leet1743
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
    pub fn restore_array(adjacent_pairs: Vec<Vec<i32>>) -> Vec<i32> {
        let NMAX = 10000;
        let mut A = Vec::new(); A.reserve(adjacent_pairs.len());
        let mut M = HashMap::new();
        for v in adjacent_pairs.iter() {
            let (x, y) = (v[0], v[1]);
            (*M.entry(x).or_insert(vec![])).push(y);
            (*M.entry(y).or_insert(vec![])).push(x);
        }

        let mut prev = 0;
        for (&x, v) in M.iter() {
            if v.len() == 1 { prev = x; A.push(x); break; }
        }
        let mut x = M.get(&prev).unwrap()[0];
        A.push(x);

        loop {
            let v = M.get(&x).unwrap();
            if v.len() == 1 { break; }
            if v[0] == prev { prev = x;  x = v[1]; }
            else { prev = x; x = v[0]; }
            A.push(x);
        }

        A
    }
}

fn main() {
    println!("ans = {:?}", Solution::restore_array(vec2d![[2,1],[3,4],[3,2]]));
    println!("ans = {:?}", Solution::restore_array(vec2d! [[4,-2],[1,4],[-3,1]]));
    println!("ans = {:?}", Solution::restore_array(vec2d![[100000,-100000]]));
}
