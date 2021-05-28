// leet1707
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

struct Trie {
    val: i32,
    next: Vec<Option<Box<Trie>>>,
}

impl Trie {
    pub fn new () -> Self {
        Trie { val: i32::MAX, next: vec![None, None]}
    }

    pub fn insert(&mut self, x: i32) {
        let mut y = 1<<30;
        let mut p = self;
        while y > 0 {
            let v = if (y & x) > 0 { 1 } else { 0 };
            if p.next[v].is_none() { p.next[v] = Some(Box::new(Self::new())); }
            p.val = min(p.val, x); y >>= 1;
            p = p.next[v].as_mut().unwrap();
        }
        p.val = x;
    }

    pub fn query(& self, x: i32, M: i32) -> i32 {
        let mut y = 1<<30;
        let mut p = self;
        if p.val > M { -1 }
        else {
            while y > 0 {
                let mut v = if (y & x) > 0 { 0 } else { 1 };
                if p.next[v].is_none() || p.next[v].as_ref(). unwrap().val > M { v = 1 - v; }
                p = p.next[v].as_ref().unwrap(); y >>= 1;
            }
            p.val ^ x
        }
    }
}

impl Solution {
    pub fn maximize_xor(A: Vec<i32>, Q: Vec<Vec<i32>>) -> Vec<i32> {
        let mut trie = Trie::new();
        for x in A { trie.insert(x); }
        
        let mut ans = Vec::new(); ans.reserve(Q.len());
        for q in Q {
            let (x, M) = (q[0], q[1]);
            ans.push( trie.query(x, M) );
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::maximize_xor(vec! [0,1,2,3,4], vec2d! [[3,1],[1,3],[5,6]]));
    println!("ans = {:?}", Solution::maximize_xor(vec! [5,2,4,6,6,3], vec2d![[12,4],[8,1],[6,3]]));
}
