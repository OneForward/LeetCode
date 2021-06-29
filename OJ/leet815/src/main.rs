// leet815
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
    pub fn num_buses_to_destination(mut routes: Vec<Vec<i32>>, source: i32, target: i32) -> i32 {
        let N = routes.len();
        let mut f: HashMap<i32, Vec<usize>> = HashMap::new();
        for (i, bus) in routes.iter().enumerate() {
            for &pos in bus {
                let entry = f.entry(pos).or_insert(Vec::new());
                entry.push(i);
            }
        }

        let mut Q = VecDeque::new();
        Q.push_back(source);
        let mut ans = 0; let mut found = false;
        if source == target { Q.clear(); found = true; }
        'outer: while !Q.is_empty() {
            let len = Q.len();  ans += 1;
            for _ in 0..len {
                if let Some(u) = Q.pop_front() {
                    for &bus in f[&u].iter() {
                        for &v in routes[bus].iter() {
                            if v == target { found = true; break 'outer; }
                            Q.push_back(v);
                        }
                        routes[bus].clear();
                    }
                }
            }
            
        }

        if found  { ans }
        else { -1 }
    }
}

fn main() {
    println!("ans = {:?}", Solution::num_buses_to_destination(vec2d![[1,7],[3,5]], 5, 5));
    println!("ans = {:?}", Solution::num_buses_to_destination(vec2d![[1,2,7],[3,6,7]], 1, 6));
    println!("ans = {:?}", Solution::num_buses_to_destination(vec2d![[7,12],[4,5,15],[6],[15,19],[9,12,13]], 15, 12));
    println!("ans = {:?}", Solution::num_buses_to_destination(vec2d![[2],[2,8]], 8, 2));
    println!("ans = {:?}", Solution::num_buses_to_destination(vec2d![[24],[3,6,11,14,22],[1,23,24],[0,6,14],[1,3,8,11,20]], 20, 8));
}
