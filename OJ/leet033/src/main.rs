// leet033
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize};
use std::cmp::{max, min};

impl Solution {
    // 两次搜索
    pub fn search1(A: Vec<i32>, target: i32) -> i32 {
        let (x0, N) = ( A[0], A.len());

        fn f1(mut lft: usize, mut rht: usize, x: i32, A: &Vec<i32>) -> usize {
            while lft < rht {
                let mid = (lft + rht) / 2;
                if A[mid] < x { rht = mid; }
                else { lft = mid + 1;}
            }
            lft
        }
        fn f2(mut lft: usize, mut rht: usize, x: i32, A: &Vec<i32>) -> i32 {
            let R = rht;
            while lft < rht {
                let mid = (lft + rht) / 2;
                if A[mid] >= x { rht = mid; }
                else { lft = mid + 1;}
            }
            if lft == R || A[lft] != x { -1 }
            else { lft as i32 }
        }

        let p = f1(0, N, x0, &A);
        if target < x0 {
            f2(p, N, target, &A)
        }
        else {
            f2(0, p, target, &A)
        }
    }
}

impl Solution {
    // 一次搜索
    pub fn search(A: Vec<i32>, target: i32) -> i32 {
        let (x0, N) = ( A[0], A.len());
        let (mut lft, mut rht) = (0, N);
        while lft < rht {
            let mid = (lft + rht) / 2;
            if target < x0 { // back
                if A[mid] < target || A[mid] >= x0  { lft = mid + 1; }
                else { rht = mid; }
            }
            else { // front
                if A[mid] >= target || A[mid] < x0 { rht = mid; }
                else { lft = mid + 1; }
            }
        }
        if lft == N || A[lft] != target { -1 }
        else { lft as i32 }
    }
}

fn main() {
    println!("ans = {:?}", Solution::search(vec! [1,3], 2));
    println!("ans = {:?}", Solution::search(vec! [4,5,6,7,0,1,2], 0));
    println!("ans = {:?}", Solution::search(vec! [4,5,6,7,0,1,2], 3));
    println!("ans = {:?}", Solution::search(vec! [4,5,6,7,0,1,2], 4));
    println!("ans = {:?}", Solution::search(vec! [4,5,6,7,0,1,2], 2));
    println!("ans = {:?}", Solution::search(vec! [4,5,6,7,0,1,2], 8));
    println!("ans = {:?}", Solution::search(vec! [1], 0));
}
