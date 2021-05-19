// leet692
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

use std::cmp::Ordering;
#[derive(Clone, Eq, PartialEq)]
struct Pair {
    s: String,
    cnt: i32,
}

// The priority queue depends on `Ord`.
// Explicitly implement the trait so the queue becomes a min-heap
// instead of a max-heap.
impl Ord for Pair {
    fn cmp(&self, other: &Self) -> Ordering {
        // Notice that the we flip the ordering on costs.
        // In case of a tie we compare positions - this step is necessary
        // to make implementations of `PartialEq` and `Ord` consistent.
        other.cnt.cmp(&self.cnt)
            .then_with(|| self.s.cmp(&other.s))
    }
}

// `PartialOrd` needs to be implemented as well.
impl PartialOrd for Pair {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn top_k_frequent(words: Vec<String>, k: i32) -> Vec<String> {
        let mut Counter = HashMap::new();
        for word in words.iter() {
            let entry = Counter.entry(word).or_insert(0);
            *entry += 1;
        }
        
        let mut k = k as usize;
        let mut Q = BinaryHeap::new();
        for (word, cnt) in Counter {
            Q.push(Pair{s: word.clone(), cnt});
            if Q.len() > k { Q.pop() ;}
        }
        let mut ans = vec![String::new(); k];
        while let Some(word) = Q.pop() {
            ans[k-1] = word.s.clone(); k -= 1;
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::top_k_frequent(vec_string!["i", "love", "leetcode", "i", "love", "coding"], 2));
}
