// lcci08.02
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
    pub fn path_with_obstacles(mut G: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (R, C) = (G.len(), G[0].len());
        fn dfs(x: usize, y: usize, path: &mut Vec<Vec<i32>>, R: usize, C: usize, G: &mut Vec<Vec<i32>>) -> bool {
            if x >= R || y >= C || G[x][y] == 1 { false }
            else {
                path.push(vec![x as i32, y as i32]);
                G[x][y] = 1;

                if (x == R-1 && y == C-1) ||
                    dfs(x + 1, y, path, R, C, G) ||
                    dfs(x, y + 1, path, R, C, G) { true }
                else {
                    path.pop();
                    false
                }
            }
        }
        let mut path = Vec::new();
        dfs(0, 0, &mut path, R, C, &mut G);  
        path 
    }
}

fn main() {
    println!("ans = {:?}", Solution::path_with_obstacles(vec2d![
        [0,0,0],
        [0,1,0],
        [0,0,0]
      ]));
    println!("ans = {:?}", Solution::path_with_obstacles(vec2d![
        [0]
      ]));
    println!("ans = {:?}", Solution::path_with_obstacles(vec2d![
        [1]
    ]));
    println!("ans = {:?}", Solution::path_with_obstacles(vec2d![
        [0,0,0,0,0],
        [0,0,0,0,1],
        [0,0,0,1,0],
        [0,0,0,0,0]
    ]));
}
