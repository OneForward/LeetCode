// leet787
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
    pub fn find_cheapest_price(n: i32, flights: Vec<Vec<i32>>, src: i32, dst: i32, K: i32) -> i32 {
        let (mut cost, mut oldcost) = (vec![i32::MAX / 2; 105], vec![i32::MAX / 2; 105]);

        let (src, dst) =  (src as usize, dst as usize) ;

        oldcost[src] = 0;
        for k in 0..=K {
            for e in flights.iter() {
                let (u, v, w) = (e[0] as usize, e[1] as usize, e[2]);
                cost[v] = min(cost[v], oldcost[u] + w);
            }
            oldcost.copy_from_slice(&cost);
        }

        if cost[dst] == i32::MAX/2 { -1 }
        else { cost[dst] }
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_cheapest_price(3, vec2d![[0,1,100],[1,2,100],[0,2,500]], 0, 2, 1 ));
    println!("ans = {:?}", Solution::find_cheapest_price(3, vec2d![[0,1,100],[1,2,100],[0,2,500]], 0, 2, 0 ));
}
