// leet304
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::collections::HashMap;

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

struct NumMatrix {
    mat : Vec<Vec<i32>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumMatrix {

    fn new(matrix: Vec<Vec<i32>>) -> Self {
        // 12ms, 非常简单的矩形割补法
        let n = matrix.len();
        if n == 0 {
            return NumMatrix {
                mat: vec![vec![]]
            }
        }

        let m = matrix[0].len();

        let mut mat = vec![vec![0; m+1]; n+1];

        for i in 1..=n {
            for j in 1..=m {
                mat[i][j] = matrix[i-1][j-1] + mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1];
            }
        }

        NumMatrix {
            mat: mat
        }
    }
    
    fn sum_region(&self, row1: i32, col1: i32, row2: i32, col2: i32) -> i32 {
        let row1 = row1 as usize;
        let row2 = row2 as usize + 1;
        let col1 = col1 as usize;
        let col2 = col2 as usize + 1;
        self.mat[row2][col2] + self.mat[row1][col1] - self.mat[row1][col2] - self.mat[row2][col1]
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix::new(matrix);
 * let ret_1: i32 = obj.sum_region(row1, col1, row2, col2);
 */



fn main() {
    let M = NumMatrix::new( vec![
        vec![3, 0, 1, 4, 2],
        vec![5, 6, 3, 2, 1],
        vec![1, 2, 0, 1, 5],
        vec![4, 1, 0, 1, 7],
        vec![1, 0, 3, 0, 5]
      ]);
    // println!("ans = {:?}", M.sum_region(1,2,3,4));
    println!("ans = {:?}", M.sum_region(1,1,2,2));
    // println!("ans = {:?}", M.sum_region(1,2,3,4));
}
