// leet447
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
    pub fn number_of_boomerangs(points: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let distance  = |p1: &Vec<i32>, p2: &Vec<i32>| {
            let (x1, y1) = (p1[0], p1[1]);
            let (x2, y2) = (p2[0], p2[1]);
            let (dx, dy) = ((x1 - x2), (y1 - y2));
            dx * dx + dy * dy 
        };
        for p1 in points.iter() {
            let mut Counter = HashMap::new();
            for p2 in points.iter() {
                let d = distance(p1, p2);
                (*Counter.entry(d).or_insert(0)) += 1;
            }
            for cnt in Counter.values() {
                ans += cnt * (cnt - 1);
            }
        }
        ans
    }
}
fn main() {
    println!("ans = {:?}", Solution::number_of_boomerangs(vec2d![[0,0],[1,0],[2,0]]));
    println!("ans = {:?}", Solution::number_of_boomerangs(vec2d![[1,1],[2,2],[3,3]]));
    println!("ans = {:?}", Solution::number_of_boomerangs(vec2d![[1,1]]));
}
