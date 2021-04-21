// leet901
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}


use std::{collections::HashMap, usize};
use std::cmp::max;
use std::cmp::min;

#[derive(Default)]
struct StockSpanner {
    S: Vec<(i32, i32)>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {

    fn new() -> Self {
        StockSpanner::default()
    }
    
    fn next(&mut self, price: i32) -> i32 {

        let mut ans = 1;
        while let Some(top) = self.S.pop() {
            if top.0 <= price { ans += top.1;  }
            else { self.S.push(top); break; }
        }
        self.S.push((price, ans));
        ans
    }
}



fn main() {
    let mut S = StockSpanner::new();
    println!("{:?}", S.next(100));
    println!("{:?}", S.next(80));
    println!("{:?}", S.next(60));
    println!("{:?}", S.next(70));
    println!("{:?}", S.next(60));
    println!("{:?}", S.next(75));
    println!("{:?}", S.next(85));
}
