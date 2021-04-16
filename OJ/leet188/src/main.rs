// leet188
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::{collections::HashMap, usize};


macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

use std::cmp::max;
impl Solution {
    pub fn max_profit(K: i32, prices: Vec<i32>) -> i32 {
        let K = K as usize;
        let mut sell = vec![0; K+1];
        let mut buy = vec![i32::MIN; K+1];
        for x in prices {
            for k in 1..=K {
                buy[k] = max(buy[k], sell[k-1]-x);
                sell[k] = max(sell[k], buy[k]+x);
            }
        }
        sell[K]
    }
}

fn main() {
    println!("ans = {:?}", Solution::max_profit(2, vec![2,4,1]));
}
