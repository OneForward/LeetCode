#![allow(non_snake_case)]
// #![allow(unused_imports)]
// #![allow(unused_variables)]
// #![allow(dead_code)]
struct Solution;

use std::collections::HashSet;
use std::collections::HashMap;
pub fn issubseq(key: &String, s: &String) -> bool {
    let s = s.to_owned().into_bytes();
    let mut x = 0usize;
    let mut rst = true;
    'outer: for k in key.to_owned().into_bytes() {
        for i in x..s.len() {
            if s[i] == k {
                x = i + 1; continue 'outer;
            }
        }
        rst = false;
        break;
    }
    rst
}

impl Solution {

    pub fn find_lu_slength(strs: Vec<String>) -> i32 {
        let mut C = HashMap::new();
        for s in strs.iter() {
            *C.entry(s).or_insert(0) += 1;
        }
        let mut K = Vec::new();
        for (key, _) in C.iter() {
            K.push(key.clone())
        }
        K.sort_by(|a, b| b.len().cmp(&a.len()));
        let mut S = HashSet::new();
        let mut ans = -1i32;
        'outer: for key in K.into_iter() {
            match C.get(key) {
                Some(&1) => {
                    for s in S.iter() {
                        if issubseq(key, s) {
                            continue 'outer;
                        }
                    }
                    ans = key.len() as i32; break;
                }
                _ => {}
            }
            S.insert(key.to_string());
        }
        ans
    }
}

fn main() {

    let strs = vec![ 
        "ac".to_string(),
        "aab".to_string(), 
        "aab".to_string(), 
        "aaa".to_string(),
        "aaa".to_string(),
        "caa".to_string(),
        "caa".to_string(),
    ];
    println!("find = {:?}", 
        Solution::find_lu_slength(strs));
    println!("{:?}", issubseq(&"aa".to_string(), &"aaa".to_string()));
}