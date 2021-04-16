#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(unused_mut)]
#![allow(dead_code)]
#![allow(unused_macros)]

struct Solution;

use std::collections::HashMap;

impl Solution {
    pub fn two_sum(A: Vec<i32>, target: i32) -> Vec<i32> {
        let mut M = HashMap::new();
        for (i, &x) in A.iter().enumerate() {
            if let Some(&j) = M.get(&(target-x)) {
                return vec![i as i32, j as i32]; 
            }
            M.insert(x, i);
        }
        vec![]
    }
}
struct Solution1;
impl Solution1 {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut arr: Vec<(i32, usize)> = nums.into_iter().enumerate().map(|(a, b)| (b, a)).collect();
        arr.sort();
        let nums: Vec<i32> = arr.iter().map( |(a, b)| *a).collect();
        let index: Vec<i32> = arr.iter().map( |(a, b)| *b as i32).collect();
        let mut ans = vec![];
        for i in 0..nums.len() {
            let (j, found) = lfind(&nums, target-nums[i], i+1, nums.len());
            if found { 
                if index[i] < index[j] {ans = vec![index[i], index[j]];}
                else {ans = vec![index[j], index[i]];}
                break;
             }
        }
        ans
    }
}
fn lfind( arr: &Vec<i32>, key: i32 , mut lft: usize, mut rht: usize) -> (usize, bool) {
    // 如果找到，返回最左边的索引，如果没找到，返回仅高于它的值索引
    while lft < rht {
        let mid = (lft + rht) / 2;
        if arr[mid] >= key { rht = mid; }
        else { lft = mid + 1; }
    }
    if lft < arr.len() && arr[lft] == key { (lft, true) }
    else { (lft, false) }
}



const fn foo(n: i32) -> i32 {
    n+1
}

fn main() {
    println!("foo(5) = {:?}", foo(5));
    let mut nums = vec![2, 2, 7, 11, 15];
    let target = 4;

    // println!("arr = {:?}", arr);
    println!("ans = {:?}", Solution::two_sum(nums, target));

    let mut v = vec![1; 10];
    for vi in v.iter_mut() {
        *vi *= 2;
    }
    // println!("v = {:?}", v);
    // dbg!(v);

    let v = vec![vec![1; 4]; 3];
    println!("v = {:?}", v);
    // dbg!(v);
}
