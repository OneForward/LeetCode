// leet149
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
    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        let K = |p1: &Vec<i32>, p2: &Vec<i32>|  {
            let dy = p1[1] - p2[1];
            let dx = p1[0] - p2[0];
            // println!("dy = {:?}", dy);
            // println!("dx = {:?}", dx);
            if  dx == 0 { (10001.0f32).to_bits() }
            else { (dy as f32 / dx as f32 + f32::EPSILON ).to_bits() }
        };
        
        let N = points.len();
        let mut ans = 0;
        for i in 0..N {
            let mut M: HashMap<u32, i32> = HashMap::new();
            let mut maxPair = 0;
            for j in i+1..N {
                let k = K(&points[i], &points[j]);
                // println!("k = {:?}, points[i] = {:?}, points[j] = {:?}", k, points[i], points[j]);
                let entry = M.entry(k).or_insert(0);
                *entry += 1; maxPair = max(maxPair, *entry);
            }
            // println!("M = {:?}", M);
            ans = max(ans, maxPair + 1);
        }

        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::max_points(vec2d![]));
    println!("ans = {:?}", Solution::max_points(vec2d![[1,1]]));
    println!("ans = {:?}", Solution::max_points(vec2d![[1,1],[2,2],[3,3]]));
    println!("ans = {:?}", Solution::max_points(vec2d![[2,3],[3,3],[-5,3]]));
}
