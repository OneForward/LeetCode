// leet1713
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

impl Solution {
    pub fn min_operations(target: Vec<i32>, A: Vec<i32>) -> i32 {
        let mut M = HashMap::new();
        for x in target.iter() {
            let len = M.len();
            M.entry(x).or_insert(len);
        }

        let mut I = Vec::new(); 
        for x in A {
            if let Some(&i) = M.get(&x) {
                I.push(i);
            }
        }

        let mut v = Vec::new();
        for i in I {
            let pos = lower_bound(&v, &i);
            if pos == v.len() { v.push(i);}
            else { v[pos] = i;}
        }
        (target.len() - v.len()) as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_operations(vec![5,1,3], vec![9,4,2,3,4]));
    println!("ans = {:?}", Solution::min_operations(vec![6,4,8,1,3,2], vec! [4,7,6,2,3,8,6,1]));
}
