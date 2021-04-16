// leet224
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::{collections::HashMap, vec};

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

impl Solution {
    pub fn calculate(s: String) -> i32 {
        let s = s.as_bytes();
        let mut op = vec![1; 1];
        let mut sign = 1;
        let mut ans = 0;
        let n = s.len();
        let mut i = 0;
        while i < n {
            match s[i] as char {
                ' ' => (),
                '+' => sign = 1,
                '-' => sign = -1,
                ')' => {op.pop();},
                '(' => if let Some(last) = op.last().cloned() {
                        op.push(last * sign); sign = 1;
                    },
                _ => {
                    let mut x = 0;
                    while i < n && (s[i] as char).is_digit(10) {
                        x = x * 10 + (s[i] - '0' as u8) as i32;
                        i += 1;
                    } i -= 1;
                    if let Some(last) = op.last().cloned() {
                        ans += last * sign * x
                    }
                }
            }
            i += 1;
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::calculate("(1+(4+5+2)-3)+(6+8)".to_string()));
    println!("ans = {:?}", Solution::calculate("- (3 + (4 + 5))".to_string()));
}
