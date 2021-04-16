

struct Solution;

use std::collections::HashMap;
impl Solution {
    pub fn len_longest_fib_subseq(A: Vec<i32>) -> i32 {
        // 40ms, 动态规划 Time O(N^2) Space O(N^2)
        // f(i, j) = f(j, k) + 1; i > j > k, A[i] = A[j] + A[k]
        let n = A.len();
        let mut f = vec![vec![0; n]; n];
        let M = A.iter().enumerate().map(|(i, x)| (x, i)).collect::<HashMap<_,_>>();
        for i in 0..n {
            for j in 0..i {
                if A[i] - A[j] < A[j] {
                    if let Some(&k) = M.get(& (A[i] - A[j]))  {
                        f[i][j] = f[j][k] + 1;
                    }
                }
            }
        }
        match f.iter().flat_map(|r| {
            r.iter().max()
        }).max() {
            Some(0) => 0,
            Some(&ans) => ans + 2,
            None => 0
        }
        
    }
}

fn main() {
    println!("ans = {:?}", Solution::len_longest_fib_subseq(vec![1,2,3,4,5,6,7,8]));
    println!("ans = {:?}", Solution::len_longest_fib_subseq(vec![1,3,7,11,12,14,18]));
}
