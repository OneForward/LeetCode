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

struct Pair {
    price : i32,
    day: i32,
}

struct StockSpanner {
    today: i32,
    S: Vec<Pair>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {

    fn new() -> Self {
        StockSpanner{today: 0, S: Vec::new()}
    }
    
    fn next(&mut self, price: i32) -> i32 {
        while let Some(top) = self.S.last() {
            if top.price <= price { self.S.pop(); }
            else { break; }
        }
        self.today += 1;
        let mut ans = self.today;
        if let Some(top) = self.S.last() {
            ans -= top.day;
        }
        self.S.push(Pair { price: price, day: self.today });
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
