// leet036
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
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut ok = true;
        let mut f = vec![0; 9];
        'outer: for i in 0..9 {
            for j in 0..9 {
                if board[i][j] == '.' { continue; }
                let x = board[i][j] as u8 - '1' as u8;
                let k = i / 3 * 3 + j / 3;
                let row = 1 << x;
                let col = 1 << 9 << x;
                let square = 1 << 18 << x;
                if ((f[i] & row) | (f[j] & col)  | (f[k] & square)) != 0 { ok = false; break 'outer; }
                f[i] |= row; f[j] |= col;  f[k] |= square;
            }
        }
        ok
    }
}

fn main() {
    println!("ans = {:?}", Solution::is_valid_sudoku( vec2d!
            [['5','3','.','.','7','.','.','.','.']
            ,['6','.','.','1','9','5','.','.','.']
            ,['.','9','8','.','.','.','.','6','.']
            ,['8','.','.','.','6','.','.','.','3']
            ,['4','.','.','8','.','3','.','.','1']
            ,['7','.','.','.','2','.','.','.','6']
            ,['.','6','.','.','.','.','2','8','.']
            ,['.','.','.','4','1','9','.','.','5']
            ,['.','.','.','.','8','.','.','7','9']]));
    println!("ans = {:?}", Solution::is_valid_sudoku( vec2d!
        [['8','3','.','.','7','.','.','.','.']
        ,['6','.','.','1','9','5','.','.','.']
        ,['.','9','8','.','.','.','.','6','.']
        ,['8','.','.','.','6','.','.','.','3']
        ,['4','.','.','8','.','3','.','.','1']
        ,['7','.','.','.','2','.','.','.','6']
        ,['.','6','.','.','.','.','2','8','.']
        ,['.','.','.','4','1','9','.','.','5']
        ,['.','.','.','.','8','.','.','7','9']] ));
}
