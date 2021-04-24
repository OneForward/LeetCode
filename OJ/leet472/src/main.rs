// leet472
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
    pub fn find_all_concatenated_words_in_a_dict(words: Vec<String>) -> Vec<String> {
        // 100%, 228ms, 普通的 递归+剪枝
        let words: HashSet<String> = words.into_iter().collect();
        let mut visited: HashSet<String> = HashSet::new();
        
        fn f(words:&HashSet<String>, visited: &mut HashSet<String>, word: &String, first: bool) ->bool {
            if ! first && words.contains(word) { true }
            else {
                for i in 1..word.len() {
                    if words.contains( &word[..i].to_string() ) {
                        let rht = word[i..].to_string();
                        if visited.contains(&rht) {continue;}
                        if f(words, visited, &rht, false) { return  true; }
                        visited.insert(rht);
                    }
                }
                false
            }
        }

        let mut ans = Vec::new();
        for word in words.iter() {
            if f(&words, &mut visited, &word, true) { ans.push(word.clone()); }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_all_concatenated_words_in_a_dict(vec_string!["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]));
    println!("ans = {:?}", Solution::find_all_concatenated_words_in_a_dict(vec_string!["a","aa","aaa"]));
}
