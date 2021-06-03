// leet1865
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*};
struct FindSumPairs {
    A: Vec<i32>,
    B: Vec<i32>,
    CB: HashMap<i32, i32>,
}


impl FindSumPairs {

    fn new(A: Vec<i32>, B: Vec<i32>) -> Self {
        let mut CB = HashMap::new();
        for &x in B.iter() {
            let entry = CB.entry(x).or_insert(0);
            *entry += 1;
        }
        FindSumPairs{ A: A, B: B, CB: CB}
    }
    
    fn add(&mut self, i: i32, dx: i32) {
        let i = i as usize;

        let entry = self.CB.entry(self.B[i]).or_insert(0);
        *entry -= 1;

        self.B[i] += dx;
        
        let entry = self.CB.entry(self.B[i]).or_insert(0);
        *entry += 1;
    }
    
    fn count(&self, tot: i32) -> i32 {
        let mut ans = 0;
        for &x in self.A.iter() {
            if self.CB.contains_key( &(tot - x) ) {
                ans += self.CB[&(tot - x)];
            }
        }
        ans
    }
}


fn main() {
    let mut findSumPairs =  FindSumPairs::new(vec![1, 1, 2, 2, 2, 3], vec![1, 4, 5, 2, 5, 4]);
    println!("{:?}", findSumPairs.count(7));  // 返回 8 ; 下标对 (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) 满足 2 + 5 = 7 ，下标对 (5,1), (5,5) 满足 3 + 4 = 7
    findSumPairs.add(3, 2); // 此时 nums2 = [1,4,5,4,5,4]
    println!("{:?}", findSumPairs.count(8));  // 返回 2 ；下标对 (5,2), (5,4) 满足 3 + 5 = 8
    println!("{:?}", findSumPairs.count(4));  // 返回 1 ；下标对 (5,0) 满足 3 + 1 = 4
    findSumPairs.add(0, 1); // 此时 nums2 = [2,4,5,4,5,4]
    findSumPairs.add(1, 1); // 此时 nums2 = [2,5,5,4,5,4]
    println!("{:?}", findSumPairs.count(7));  // 返回 11 ；下标对 (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) 满足 2 + 5 = 7 ，下标对 (5,3), (5,5) 满足 3 + 4 = 7

}
