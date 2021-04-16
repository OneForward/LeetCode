#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(unused_mut)]
#![allow(dead_code)]
#![allow(unused_macros)]
use std::collections::HashMap;

struct Solution;


impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        // leet013, 4ms
        let D = |&ch: &char| {
            match &ch {
                'I' => 1, 'V' => 5, 'X' => 10, 'L' => 50, 'C' => 100, 'D' => 500, 'M' => 1000,
                _  => 0,
            }
        };
        let v: Vec<char> = s.chars().collect();
        let mut sum = 0;
        for i in 0..v.len()-1 {
            if  D(&v[i]) < D(&v[i+1]) { sum -= D(&v[i]); }
            else { sum += D(&v[i]); }
        }
        sum += D(&v[v.len()-1]);
        return sum;
    }
}


fn main() {
    




    let s = "MCMXCIV".to_string();

    let x = Solution::roman_to_int(s);
    
    println!("ans = {:?} ", x);
}
