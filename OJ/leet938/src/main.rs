// leet938
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        if let Some(root) = root {
            let mut ans = 0;
            let x = root.borrow().val;
            if x > low { ans += Solution::range_sum_bst(root.borrow().left.clone(), low, high); }
            if x < high { ans += Solution::range_sum_bst(root.borrow().right.clone(), low, high); }
            if low <= x && x <= high { ans += x; }
            ans
        }
        else { 0 }
    }
}

use std::collections::*;
use std::cmp::{max, min};

impl Solution {
    pub fn method()  {
    }
}

fn main() {
    println!("x = {:?}", Solution::range_sum_bst( tree![10,5,15,3,7,null,18] , 7, 15));
    println!("ans = {:?}", Solution::method());
}
