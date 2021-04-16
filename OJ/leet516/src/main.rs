struct Solution;

use std::mem::swap;
use std::cmp::max;

impl Solution {
    pub fn longest_palindrome_subseq1(s: String) -> i32 {
        // 16ms, O(n^2), O(n)
        let s = s.as_bytes();
        let n = s.len();
        let mut f = vec![0; n+1];
        for i in 1..=n {
            let mut tmp = f[0];
            for j in 1..=n {
                if s[i-1] == s[n-j] { 
                    swap(&mut tmp, &mut f[j]);
                    f[j] += 1;
                }
                else {
                    tmp = f[j]; f[j] = max(f[j-1], f[j]);
                }
            }
        }
        f[n]
    }
    pub fn longest_palindrome_subseq(s: String) -> i32 {
        // 4ms, O(n^2), O(n)
        let s = s.as_bytes();
        let n = s.len();
        let mut f = vec![0; n];
        let mut maxVal;
        for i in 0..n {
            f[i] = 1; maxVal = 0;
            for j in (0..i).rev() {
                let tmp = f[j];
                if s[i] == s[j] { 
                    f[j] = maxVal + 2;
                }
                maxVal = max(tmp, maxVal);
            }
        }
        match f.iter().max() {
            Some(&x) => x,
            None => 0
        }
    }
}

fn main() {
    
    println!("ans = {:?}", Solution::longest_palindrome_subseq( "bbbab".to_string() ));
}
