// leet373
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


use std::{collections::BinaryHeap};
use std::cmp::{max, min, Reverse};

impl Solution {
    pub fn k_smallest_pairs(A: Vec<i32>, B: Vec<i32>, K: i32) -> Vec<Vec<i32>> {
        let (N, M) = (A.len(), B.len());
        let K = min(K as usize, N * M );
        let mut ans: Vec<Vec<i32>> = Vec::new(); ans.reserve(K);
        let mut Q = BinaryHeap::new();
        for i in 0..N {
            Q.push(Reverse((A[i] + B[0], i, 0)));
        }
        for _ in 0..K {
            if let Some(Reverse((_, i, mut j))) = Q.pop() {
                ans.push(vec![A[i], B[j]]);
                j += 1;
                if j < M { Q.push(Reverse((A[i] + B[j], i, j)) ); }
            }
        }
        ans

    }
}

fn main() {
    println!("ans = {:?}", Solution::k_smallest_pairs( vec![1,7,11],  vec![2,4,6],  3));
    println!("ans = {:?}", Solution::k_smallest_pairs( vec![1,1,2],  vec![1,2,3],  2));
    println!("ans = {:?}", Solution::k_smallest_pairs( vec![1,2],  vec![3],  3 ));
}


