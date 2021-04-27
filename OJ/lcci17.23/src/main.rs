// lcci17.23
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

impl Solution {
    pub fn find_square(M: Vec<Vec<i32>>) -> Vec<i32> {
        let (MAX, N) = (201, M.len() );
        let (mut f, mut g) = (vec![vec![0; MAX]; MAX], vec![vec![0; MAX]; MAX]);
        for x in 0..N {
            for y in 0..N {
                if M[x][y] == 0 {
                    f[x+1][y+1] = f[x+1][y] + 1;
                    g[x+1][y+1] = g[x][y+1] + 1;
                }
            }
        }
        
        let (mut i, mut j, mut ans) = (0, 0, 0);
        let mut found = false;
        'outer: for len in (1..=N).rev() {
            for x in 0..=N-len {
                for y in 0..=N-len {
                    if min![f[x+len][y+len], g[x+len][y+len], 
                            f[x+1][y+len]  , g[x+len][y+1]] >= len {
                        i = x as i32; j = y as i32; ans = len as i32; found = true; break 'outer;
                    }
                }
            }
        }
        if found { vec![i, j, ans] }
        else { vec![] }
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_square( vec2d!
    [
        [1,0,1],
        [0,0,1],
        [0,0,1]
    ]
    ));
    println!("ans = {:?}", Solution::find_square( vec2d!
    [
        [0,1,1],
        [1,0,1],
        [1,1,0]
    ]
    ));
    println!("ans = {:?}", Solution::find_square( vec2d!
        [[1, 1, 1, 1, 0, 1, 0, 1, 1, 1],
        [1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 0, 1, 0, 1, 0, 1],
        [1, 1, 1, 1, 0, 0, 0, 0, 0, 0],
        [1, 0, 1, 0, 1, 1, 1, 1, 1, 1],
        [1, 1, 0, 0, 1, 0, 1, 0, 0, 1],
        [0, 0, 0, 1, 1, 1, 0, 1, 0, 1],
        [0, 0, 0, 1, 0, 1, 0, 1, 0, 1],
        [1, 0, 1, 0, 1, 1, 0, 1, 1, 1],
        [1, 1, 1, 0, 1, 0, 0, 1, 1, 1]]
    ));
}
