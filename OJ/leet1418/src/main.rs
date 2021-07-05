// leet1418
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::collections::HashMap;

impl Solution {
    pub fn display_table(orders: Vec<Vec<String>>) -> Vec<Vec<String>> {
        let mut M: HashMap<String, usize> = HashMap::new();
        let mut tables = vec![ HashMap::new(); 501  ];
        for o in orders {
            let (tid, food) = (o[1].parse::<usize>().unwrap(), o[2].clone());
            let len = M.len();
            let fid = M.entry(food).or_insert(len);
            let entry = tables[tid].entry(*fid).or_insert(0);
            *entry += 1;
        }
        let mut foods: Vec<String> = M.keys().cloned().collect();
        foods.sort();

        let mut ans = vec![vec!["Table".to_string()]];
        ans[0].append(&mut foods.clone());
        for (tid, table) in tables.iter().enumerate() {
            if table.is_empty() { continue; }
            let mut v = vec!["0".to_string(); foods.len() + 1];
            v[0] = tid.to_string();
            for (i, food) in foods.iter().enumerate() {
                if let Some(&cnt) = table.get( M.get(food).unwrap() ) {
                    v[i+1] = cnt.to_string();
                }
            }
            ans.push(v);
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::display_table(vec_of_strings2d![["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]));
    println!("ans = {:?}", Solution::display_table(vec_of_strings2d![["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]));
    println!("ans = {:?}", Solution::display_table(vec_of_strings2d![["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]));
}
