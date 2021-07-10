// leet1390
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
    pub fn sum_four_divisors(A: Vec<i32>) -> i32 {
        let mut f = vec![0; 100005];
        let mut isPrime = vec![true; 100005];
        let mut P = vec![]; 
        let M = *A.iter().max().unwrap() as usize + 1;

        for x in 2..M {
            if !isPrime[x] {  continue; }
            let mut y = 2 * x; P.push(x);
            while y < M {
                isPrime[y] = false;  y += x;
            }
        }
        
        let N = P.len();
        
        for i in 0..N {
            let y = P[i] * P[i] * P[i];
            if y < M { f[y] = 1 + P[i] + P[i] * P[i] + y; }
            else { break; }
        }
        for i in 0..N {
            if P[i] * P[i] >= M { break; }
            for j in (i+1)..N {
                let y = P[i] * P[j];
                if y < M {
                    f[y] = (1 + P[i]) * (1 + P[j]);
                }
                else { break; }
            }
        }
        
        A.iter().fold(0, |a, &b| a + f[b as usize] as i32)
    }
}

fn main() {
    println!("ans = {:?}", Solution::sum_four_divisors(vec![21,4,7]));
}
