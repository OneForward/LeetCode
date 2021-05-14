// leet012
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
use std::cmp::{max, min};

impl Solution {
    pub fn int_to_roman(x: i32) -> String {
        let x = x as usize;
        let thousands = ["", "M", "MM", "MMM"];
        let hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
        let tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
        let ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];
        thousands[x / 1000].to_owned() + hundreds[x / 100 % 10] + 
        tens[x / 10 % 10] + ones[x % 10]
    }
}

fn main() {
    println!("ans = {:?}", Solution::int_to_roman(10));
    println!("ans = {:?}", Solution::int_to_roman(3));
    println!("ans = {:?}", Solution::int_to_roman(4));
    println!("ans = {:?}", Solution::int_to_roman(9));
    println!("ans = {:?}", Solution::int_to_roman(58));
    println!("ans = {:?}", Solution::int_to_roman(1994));
}
