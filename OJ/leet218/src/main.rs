// leet218
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;

use std::collections::BTreeMap;

impl Solution {
    pub fn get_skyline(buildings: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        
        let mut ans = Vec::new();

        let mut A = Vec::new();
        for v in buildings {
            A.push( (v[1], v[2]) );
            A.push( (v[0], -v[2]) );
        }

        A.sort();

        let mut H = BTreeMap::new(); H.insert(0, 1);
        for (x, h) in A {
            if h > 0 { 
                if let Some(cnt) = H.get_mut( &h) {
                    *cnt -= 1;
                    if *cnt == 0 { H.remove(&h); };
                }
                let rh = *H.iter().next_back().unwrap().0;
                if h > rh { ans.push(vec![x, rh] ); }
            }
            else { 
                let rh = *H.iter().next_back().unwrap().0;
                *H.entry(-h).or_default() += 1; 
                if -h > rh { ans.push(vec![x,  -h]) ;}
                
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::get_skyline(vec2d![[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]));
    println!("ans = {:?}", Solution::get_skyline(vec2d![[0,2,3],[2,5,3]]));
}
