// lcp08
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


pub fn lower_bound<T>(v: &Vec<T>, len: usize, x: &T) -> usize
where T: Ord
{
    let (mut lft, mut rht) = (0, len);
    while lft < rht {
        let mid = (lft + rht) / 2;
        if v[mid] >= *x { rht = mid; }
        else { lft = mid + 1; }
    }
    lft
}

impl Solution {
    pub fn get_trigger_time(increase: Vec<Vec<i32>>, requirements: Vec<Vec<i32>>) -> Vec<i32> {
        let (mut fx, mut fy, mut fz) = (vec![0; 10005], vec![0; 10005], vec![0; 10005]);
        let mut T = 1;
        for v in increase {
            let (x, y, z) = (v[0], v[1], v[2]);
            fx[T] = fx[T-1] + x;
            fy[T] = fy[T-1] + y;
            fz[T] = fz[T-1] + z; T += 1;
        }

        let mut ans = Vec::new(); 
        ans.reserve(requirements.len());
        for v in requirements {
            let (x, y, z) = (v[0], v[1], v[2]);
            let px = lower_bound(&fx, T, &x);
            let py = lower_bound(&fy, T, &y);
            let pz = lower_bound(&fz, T, &z);
            let pos = max!(px, py, pz);
            if pos == T { ans.push(-1); }
            else { ans.push(pos as i32); }
        }
        ans
    }
}

fn main() {
    // println!("ans = {:?}", Solution::get_trigger_time(vec2d![[2,8,4],[2,5,0],[10,9,8]],   vec2d![[2,11,3],[15,10,7],[9,17,12],[8,1,14]] ));
    // println!("ans = {:?}", Solution::get_trigger_time(vec2d![[0,4,5],[4,8,8],[8,6,1],[10,10,0]],   vec2d![[12,11,16],[20,2,6],[9,2,6],[10,18,3],[8,14,9]] ));
    println!("ans = {:?}", Solution::get_trigger_time(vec2d![[1,1,1]],   vec2d![[0,0,0]]));
}
