// leet909
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

impl Solution {
    pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
        let N = board.len();
        let N2 = N * N;
        let mut visited = vec![false; N2];
        let mut v = Vec::new(); v.reserve(500);
        let mut rev = false;
        for row in board.iter().rev() {
            if rev {
                for &x in row.iter().rev() { v.push(x); }
            }
            else { 
                for &x in row { v.push(x); }
            }
            rev = !rev;
        }

        let mut ans = 0;
        let mut found = false;
        let mut Q = VecDeque::new();
        Q.push_back(0); visited[0] = true; 
        'outer: while !Q.is_empty() {
            let len = Q.len(); ans += 1;
            for _ in 0..len {
                if let Some(x) = Q.pop_front() {
                    for mut p in x+1..=x+6 {
                        if p < N2 {
                            if v[p] != -1 {
                                p = v[p]  as usize - 1;
                            }
                            if p == N2-1 { found = true; break 'outer; }
                            if !visited[p] { visited[p] = true; Q.push_back(p); }
                        }
                    }
                }
            }
        }
        if found { ans } 
        else { -1 }
    }
}

fn main() {
    println!("ans = {:?}", Solution::snakes_and_ladders(vec2d![
        [-1,-1,-1,-1,-1,-1],
        [-1,-1,-1,-1,-1,-1],
        [-1,-1,-1,-1,-1,-1],
        [-1,35,-1,-1,13,-1],
        [-1,-1,-1,-1,-1,-1],
        [-1,15,-1,-1,-1,-1]]
    ));
    println!("ans = {:?}", Solution::snakes_and_ladders(vec2d!
        [[-1,-1,-1,-1,48,5,-1],[12,29,13,9,-1,2,32],[-1,-1,21,7,-1,12,49],[42,37,21,40,-1,22,12],[42,-1,2,-1,-1,-1,6],[39,-1,35,-1,-1,39,-1],[-1,36,-1,-1,-1,-1,5]]
    ));
    println!("ans = {:?}", Solution::snakes_and_ladders(vec2d!
        [[1,1,-1],[1,1,1],[-1,1,1]]
    ));
}
