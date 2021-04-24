// leet515
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


use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;
use std::cmp::{min, max};
impl Solution {
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut Q = VecDeque::new();
        if let Some(node) = root { Q.push_back(node); }

        while !Q.is_empty() {
            let mut v = i32::MIN;
            for _ in 0..Q.len() {
                if let Some(node) = Q.pop_front() {
                    v = max(v, node.borrow().val);
                    if let Some(left) = node.borrow().left.clone() { Q.push_back(left); }
                    if let Some(right) = node.borrow().right.clone() { Q.push_back(right); }
                }
            }
            ans.push(v);
        }
        ans
    }
}


fn main() {
    println!("{:?}", Solution::largest_values(tree![1,3,2,5,3,null,9]) );
    println!("{:?}", Solution::largest_values(tree![1,2,3]) );
}


