// leet1791
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]


macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

macro_rules!vec2d {
    [ $( [ $( $d:expr ),* ] ),* ] => {
        vec![
            $(
                vec![$($d),*],
            )* 
        ]
    }
}

struct Solution;


use std::collections::HashMap;
use std::cmp::{max, min};

impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        let (e1, e2) = (&edges[0], &edges[1]);
        let (u1, v1, u2, v2) = (e1[0], e1[1], e2[0], e2[1]);
        if u1 == u2 || u1 == v2 { u1 }
        else {v1}
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_center(vec2d![[1,2],[2,3],[4,2]]));
    println!("ans = {:?}", Solution::find_center(vec2d![[1,2],[5,1],[1,3],[1,4]]));
}
