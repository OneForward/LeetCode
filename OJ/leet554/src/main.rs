// leet554
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
    pub fn least_bricks(wall: Vec<Vec<i32>>) -> i32 {
        let len = wall.len() as i32;
        let mut Counter: HashMap<i32,i32> = HashMap::new();
        for L in wall {
            let mut sum = 0;
            for x in L {
                sum += x;
                let entry = Counter.entry(sum).or_insert_with(|| 0);
                *entry += 1;
            }
            let entry = Counter.entry(sum).or_insert_with(|| 0);
            *entry -= 1;
        }
        
        if let Some(x) = Counter.values().max() {
            len - x 
        }
        else { len } 
    }
}

fn main() {
    println!("ans = {:?}", Solution::least_bricks(vec2d![[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]));
    println!("ans = {:?}", Solution::least_bricks(vec2d![[1],[1],[1]]));
}
