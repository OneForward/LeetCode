struct Solution;

use std::cmp::max;

impl Solution {
    pub fn find_lu_slength(a: String, b: String) -> i32 {
        if a == b { -1 }
        else { 
            max( a.len(), b.len() ) as i32
        }
    }
}

fn main() {
    println!("find = {:?}",
     Solution::find_lu_slength(
        "aba".to_string(),
        "abac".to_string(),
    ));
}