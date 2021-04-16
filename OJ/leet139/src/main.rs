// leet139

struct Solution;

use std::collections::HashMap;
macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}


impl Solution {
    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        // 0ms, 完全背包问题, 注意这个问题的 v 和 w 的循环顺序
        let n = s.len();
        let mut f = vec![false; n+1];
        f[0] = true;
        for v in 1..=n {
            for w in word_dict.iter() {
                if v >= w.len() && s[n-v..n-v+w.len()] == *w {
                    f[v] |= f[v-w.len()]
                }
            }
        }
        f[n]
    }
}

fn main() {
    println!("ans = {:?}", Solution::word_break("leetcode".to_string(), vec_of_strings!["leet", "code"]));
    println!("ans = {:?}", Solution::word_break("applepenapple".to_string(), vec_of_strings!["apple", "pen"]));
    println!("ans = {:?}", Solution::word_break("catsandog".to_string(), vec_of_strings!["cats", "dog", "sand", "and", "cat"]));
    println!("ans = {:?}", Solution::word_break("cars".to_string(), vec_of_strings!["car","ca","rs"]));
}
