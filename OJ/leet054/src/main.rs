#![allow(non_snake_case)]
struct Solution;

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = Vec::new();
        if matrix.len() == 0 {ans }
        else {
            let (R, C) = (matrix.len(), matrix[0].len());
            let RC = R*C;
            let mut k = 0;
            loop {
                for c in k..C-k {
                    ans.push(matrix[k][c]);
                }
                if ans.len() == RC { break; }

                for r in k+1..R-k {
                    ans.push(matrix[r][C-k-1]);
                }
                if ans.len() == RC { break; }

                for c in (k..C-k-1).rev() {
                    ans.push(matrix[R-k-1][c]);
                }
                if ans.len() == RC { break; }

                for r in ((k+1)..R-k-1).rev() {
                    ans.push(matrix[r][k]);
                }
                if ans.len() == RC { break; } 
                
                k += 1;
            }
            ans
        }
    }
}

fn main() {
    let m = vec![
        vec![1, 2, 3, 4],
        vec![5, 6, 7, 8],
        vec![9,10,11,12]
      ];
    println!("ans = {:?}", Solution::spiral_order(m));
}
