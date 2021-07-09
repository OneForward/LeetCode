// leet1828
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
    pub fn count_points(points: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = Vec::new(); ans.reserve(queries.len());
        for q in queries {
            let mut cnt = 0;
            let (x, y, r) = (q[0], q[1], q[2]);
            for p in points.iter() {
                let (px, py) = (p[0], p[1]);
                if (x - px) * (x - px) + (y - py) * (y - py) <= r * r { cnt += 1; }
            }
            ans.push(cnt);
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::count_points(vec2d![[1,1],[2,2],[3,3],[4,4],[5,5]], vec2d! [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]));
}
