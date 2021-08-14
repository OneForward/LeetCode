// leet1583
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
    pub fn unhappy_friends(n: i32, preferences: Vec<Vec<i32>>, pairs: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut f = vec![vec![n; n]; n];
        for (x, pref) in preferences.iter().enumerate() {
            for (p, &y) in pref.iter().enumerate() {
                f[x][y as usize] = p;
            }
        }
        let mut unhappy = vec![0; n];
        let mut friends = vec![0; n];
        for v in pairs.iter() {
            let (x, y) = (v[0] as usize, v[1] as usize);
            friends[x] = y;
            friends[y] = x;
        }

        for (x, &y) in friends.iter().enumerate() {
            for (u, &v) in friends.iter().enumerate() {
                if f[x][u] < f[x][y] && f[u][x] < f[u][v] {
                    unhappy[x] = 1;
                }
            }
        }
        unhappy.iter().sum()
    }
}

fn main() {
    println!("ans = {:?}", Solution::unhappy_friends(4, vec2d! [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], vec2d! [[0, 1], [2, 3]]));
    println!("ans = {:?}", Solution::unhappy_friends(2, vec2d! [[1], [0]], vec2d! [[1, 0]]));
    println!("ans = {:?}", Solution::unhappy_friends(4, vec2d! [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]],  vec2d! [[1, 3], [0, 2]]));
}
