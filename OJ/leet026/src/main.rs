// leet026
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::collections::HashMap;
use std::cmp::max;
use std::cmp::min;

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

impl Solution {
    pub fn remove_duplicates(A: &mut Vec<i32>) -> i32 {
        let mut top = 0;
        for j in 1..A.len() {
            if A[j] != A[top] { top += 1; A[top] = A[j]; }
        }
        if A.is_empty() { 0 }
        else { (top + 1) as i32 }
    }
}

fn main() {
    println!("ans = {:?}", Solution::remove_duplicates(&mut vec![0,0,1,1,1,2,2,3,3,4]));
    println!("ans = {:?}", Solution::remove_duplicates(&mut vec![]));
}
