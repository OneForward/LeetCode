// lcof53-I
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize, vec};
use std::cmp::{max, min};

pub fn lower_bound<T>(v: &Vec<T>, x: &T) -> usize
where T: Ord
{
    let (mut lft, mut rht) = (0, v.len());
    while lft < rht {
        let mid = (lft + rht) / 2;
        if v[mid] >= *x { rht = mid; }
        else { lft = mid + 1; }
    }
    lft
}

pub fn upper_bound<T>(v: &Vec<T>, x: &T) -> usize
where T: Ord
{
    let (mut lft, mut rht) = (0, v.len());
    while lft < rht {
        let mid = (lft + rht) / 2;
        if v[mid] > *x { rht = mid; }
        else { lft = mid + 1; }
    }
    lft
}



impl Solution {
    pub fn search(A: Vec<i32>, x: i32) -> i32 {
        (upper_bound(&A, &x) - lower_bound(&A, &x) ) as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::search(vec![5,7,7,8,8,10], 8));
}
