// leet1744
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
    pub fn can_eat(candies_count: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let mut f = vec![0i64; 100005];
        for i in 0..candies_count.len() {
            f[i+1] = f[i] + candies_count[i] as i64;
        }
        let mut ans = Vec::new(); ans.reserve(queries.len());
        for q in queries {
            let (i, day, M) = (q[0] as usize, q[1] as i64, q[2] as i64);
            ans.push( f[i] / M <= day && day < f[i+1] );
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::can_eat(vec![7,4,5,3,8],  vec2d![[0,2,2],[4,2,4],[2,13,1000000000]]));
    println!("ans = {:?}", Solution::can_eat(vec![5,2,6,4,1], vec2d![[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]));
}
