#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(unused_mut)]
#![allow(dead_code)]
#![allow(unused_macros)]
struct Solution;



use std::cmp::max;
use std::collections::HashMap;
impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        // 0ms, leet055
        let mut sofar = 0;
        for i in 0..nums.len() {
            if sofar < i { return  false; }
            sofar = max(nums[i] as usize + i, sofar);
        }
        return true
    }
    pub fn my_pow(mut x: f64, mut n: i32) -> f64 {
        // 0ms, leet050
        let mut ans = 1.0; 
        if n >= 0 {
            let mut n = n as u32;
            while n > 0 {
                if n % 2 == 1 { ans *= x; }
                x *= x;
                n /= 2;
            }
        }
        else {
            let mut x = 1.0 / x;
            while n < 0 {
                if n % 2 == -1 { ans *= x; }
                x *= x;
                n /= 2;
            }
        }
        ans
    }
    pub fn remove_invalid_parentheses(s: String) -> Vec<String> {
        // leet301
        vec![]
    }
    pub fn is_valid(s: String) -> bool {
        // 0ms, leet1003
        // 栈
        if s.len() % 3 != 0 { return false; }  
        let chars: Vec<char> = s.chars().collect();
        let mut stack = Vec::with_capacity(s.len()); 
        for ch in chars {
            let len = stack.len();
            if ch == 'c' {
                if len >= 2 && stack[len-2] == 'a' && stack[len-1] == 'b' {
                    stack.pop(); stack.pop();
                }
                else { return false; }
            }
            else { stack.push(ch); }
        }
        stack.len() == 0
    }
    pub fn is_valid1003(s: String) -> bool {
        // 4ms, leet1003
        if s.len() % 3 != 0 { return false; }        
        let s: Vec<char> = "$".chars().chain(s.chars()).chain("%".chars()).collect(); 
        let len = s.len();
        let mut next = vec![0; len];
        let mut prev = vec![len; len]; 
        for i in 0..len { next[i] = i + 1; }
        for i in 1..len { prev[i] = i - 1; } 
        let sub = vec!['a', 'b', 'c'];
        let mut found = vec![0; 3];
        let mut find_sub = || {
            let (mut si, mut p, mut ok) = (0, 0, 0);
            while p != len {
                if sub[si] == s[p] {
                    found[si] = p; si += 1; p = next[p];
                    if si == 3 {
                        si = 0; ok = 1;
                        let head = prev[found[0]];
                        let tail = next[found[2]];
                        next[head] = tail;
                        prev[tail] = head;
                    }
                }
                else if si > 0{ si = 0; }
                else { p = next[p]; }
            }
            if next[0] == len - 1 { ok = 2; }
            return ok;
        };

        loop {
            let ok = find_sub();
            if ok == 0 { return false; }
            if ok == 2 { return true; }
        }
    }
    pub fn is_valid_020(s: String) -> bool {
        // 0ms, leet020
        let s: Vec<char> = s.chars().collect();
        let mut stack = vec![];
        let map: HashMap<char, char> = [(')', '('), (']', '['), ('}', '{')].iter().cloned().collect();
        for si in s {
            match si {
                left if left == '(' ||  left == '{' ||  left == '[' => stack.push(left),
                ref right if map.contains_key(right) => {
                    let pop = stack.pop();
                    if Some(map[right]) != pop { return false; }
                },
                _ => {}
            }
        }
        if stack.is_empty() { true }
        else { false }
    }

    pub fn letter_combinations(digits: String) -> Vec<String> {
        // 0ms, leet017
        if digits == "" { return vec![]; }
        let arr = vec![
            vec!['a', 'b', 'c'],
            vec!['d', 'e', 'f'],
            vec!['g', 'h', 'i'],
            vec!['j', 'k', 'l'],
            vec!['m', 'n', 'o'],
            vec!['p', 'q', 'r', 's'],
            vec!['t', 'u', 'v'],
            vec!['w', 'x', 'y', 'z']];
        let words: Vec<Vec<char>> = digits.into_bytes().into_iter().map(
                            |si| arr[si as usize - '2' as usize].clone()
                            ).collect();
        let lens: Vec<usize> = words.iter().map(|s| s.len()).collect();
        let len = lens.len();
        let start: *mut Vec<usize> = &mut vec![0; len];
        let mut ans = vec![]; 
        unsafe {
            let mut ok_add_one = || {
                (*start)[len-1] += 1;
                for i in (0..len).rev() {
                    if (*start)[i] == lens[i] {
                        (*start)[i] = 0;
                        if i == 0 { return false; }
                        (*start)[i-1] += 1;
                    }
                    else { break; }
                }
                true
            };
            loop {
                let s: String = words.iter().zip((*start).iter())
                                .map(|(word, i)| word[*i]).collect();
                ans.push(s);
                if !ok_add_one() { break; }
            }
        }
        ans
    }
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        // 0ms, leet022
        unsafe fn dfs(n:i32, top: usize, cnt: i32, mut rec: Vec<char>, ans: *mut Vec<String>) {
            if cnt == n {
                rec.append(&mut vec![')'; top]);
                (*ans).push(rec.into_iter().collect());
                return;
            }
            let mut rec1 = rec.clone(); rec1.push('(');
            dfs(n, top+1, cnt+1, rec1, ans);
            if top > 0 {
                let mut rec2 = rec.clone(); rec2.push(')');
                dfs(n, top-1, cnt, rec2, ans);
            }
        }
        unsafe {
            let ans: *mut Vec<String> = &mut vec![];
            dfs(n, 0, 0, vec![], ans);
            (*ans).clone()
        }
    
    }
    pub fn longest_common_prefix(vec: Vec<String>) -> String {
        // 0ms, leet014
        if vec.len() == 0 || vec[0].len() == 0 { return "".to_string(); }
        let vec: Vec<Vec<char>> = vec.into_iter().map( |s| s.chars().collect() ).collect();
        let mut ed = 0; 
        let mut v0 = &vec[0]; let mut minlen = v0.len();
        for v in vec[1..].iter() {
            if minlen > v.len() {
                minlen = v.len(); v0 = v;
            }
        }
        for ed in 0..minlen {
            let s0 = v0[ed];
            for s in vec.iter() {
                if s[ed] != s0 { return v0[..ed].iter().collect(); }
            }
        }
        v0.iter().collect()
    }

    pub fn int_to_roman(mut x: i32) -> String {
        // 4ms, leet012
        let mut ans = vec![]; 
        let values   = [[1000, 500, 100], [100, 50, 10], [10, 5, 1]];
        let symbols  = [['M', 'D', 'C'], ['C', 'L', 'X'], ['X', 'V', 'I']];
        for j in 0..3 {
            let (vj, sj) = (values[j], symbols[j]);
            for i in 0..2 {
                while x >= vj[i] {
                    x -= vj[i];
                    ans.push(sj[i]);
                }
                if x >= vj[i] - vj[2] {
                    x -= vj[i] - vj[2];
                    ans.push(sj[2]);
                    ans.push(sj[i]);
                }
            }
        }
        while x > 0 { ans.push('I'); x -= 1;}
        ans.into_iter().collect()
    }

    pub fn max_area(arr: Vec<i32>) -> i32 {
        // 0ms, leet011
        let (mut i, mut j) = (0, arr.len()-1);
        let mut ans = 0; let mut S;
        while i < j {
            if arr[i] < arr[j] {
                S = arr[i] as usize * (j - i);
                i += 1;
            }
            else {
                S = arr[j] as usize * (j - i);
                j -= 1;
            }
            if ans < S { ans = S; }
        }
        ans as i32 
    }
    pub fn my_atoi(s: String) -> i32 {
        // 0ms, leet008
        if s == "" { return 0; }
        let s: Vec<char> = s.chars().collect();
        
        let mut len = s.len(); let mut st = len;
        for i in 0..len {
            if s[i] != ' '  { st = i; break; }
        }
        if st == len { return 0; }

        let ok_digit = |ch| {'0' <= ch && ch <= '9'};
        let ok_st = |st| { st < len-1 && ok_digit(s[st+1]) };

        let mut sign = 1;
        match s[st] {
            '0'..='9' => {},
            '+' if ok_st(st)  => { st += 1; },
            '-' if ok_st(st) => { st += 1; sign = -1; },
            _ => { return 0; }
        }

        let mut ans = 0i64;
        for i in st..len {
            if !ok_digit(s[i]) { break; }
            else {
                ans = ans * 10 + s[i] as i64 - '0' as i64;
                if ans >= 0x8000_0000  {
                    if sign > 0 { return 0x7fff_ffff; }
                    else { return -0x8000_0000; }
                }
            }
        } 
        sign * ans as i32
    }
    pub fn is_palindrome_1(mut x: i32) -> bool {
        // 12ms, leet009
        if x < 0 {return false; }
        let mut vec = vec![];
        loop {
            vec.push(x % 10);
            x /= 10;
            if x == 0 { break; }
        }
        let len = vec.len();
        for i in 0..len/2 {
            if vec[i] != vec[len-1-i] { return false; }
        }
        true
    }
    pub fn is_palindrome(x: i32) -> bool {
        // 4ms, leet009
        if x < 0 { return false; }
        let mut ans = 0; let mut x = x as u32; let x_copy = x;
        while x > 0 {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        x_copy == ans
    }
    pub fn super_egg_drop(mut k: i32, mut n: i32) -> i32 {
        // leet887, #动态规划#
        let (mut n, mut k) = (n as usize, k as u32);
        let mut g = vec![1; n];
        let mut f = vec![0; n];
        enum Marker{ F, G };
        for i in 1..n { g[i] = g[(i-1)/2] + 1; }
        for i in 1..n {
            let mut small = (0, Marker::F);
            for m in 0..(i-1)/2 {
                // let mut big = if f[m] > g[n-m-1]
            }
        }
        0
    }
    pub fn max_dist_to_closest(seats: Vec<i32>) -> i32 {
        // 0ms, leet849
        let len = seats.len();
        let (mut lft, mut rht) = (0, len-1);
        while lft < len && seats[lft] == 0 { lft += 1; }
        while seats[rht] == 0 { rht -= 1; }
        let mut prev = lft;
        let mut ans = 0;
        for i in lft+1..=rht {
            if seats[i] == 0 { continue; }
            ans = max(ans, i-prev); prev = i;
        }
        // println!("(lft, rht, ans) = {:?}", (lft as i32, len - rht - 1, ans / 2));
        max(ans as i32 / 2, max( lft as i32, (len - rht - 1) as i32 ))
    }
}
macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

fn main() {
    println!("ans = {:?}", Solution::can_jump(vec![2,3,1,1,4]));
    // println!("ans = {:?}", Solution::letter_combinations("23".to_string()));
    // println!("ans = {:?}", Solution::letter_combinations("".to_string()));
    
    // println!("ans = {:?}", Solution::generate_parenthesis(3));
    // println!("ans = {:?}", Solution::generate_parenthesis(1));
    
    // println!("ans = {:?}", Solution::my_pow(2.0, 10));
    // println!("ans = {:?}", Solution::my_pow(2.0, -0x8000_0000));
    // println!("ans = {:?}", Solution::my_pow(2.0, -2));
    // println!("ans = {:?}", Solution::my_pow(2.1, 3));
    // println!("ans = {:?}", Solution::my_pow(2.0, 0));
    // println!("ans = {:?}", Solution::my_pow(0.0, 1));
    // println!("ans = {:?}", Solution::is_valid("aabcbc".to_string()));
    // println!("ans = {:?}", Solution::is_valid("cababc".to_string()));
    // println!("ans = {:?}", Solution::is_valid("".to_string()));
    // println!("ans = {:?}", Solution::is_valid("abcabcababcc".to_string()));
    // println!("ans = {:?}", Solution::is_valid("abccba".to_string()));

    // println!("ans = {:?}", Solution::is_valid("()".to_string()));
    // println!("ans = {:?}", Solution::is_valid("([[{}]])".to_string()));
    // println!("ans = {:?}", Solution::is_valid("[{[[[[]]]]}])".to_string()));
    
    // println!("ans = {:?}", Solution::longest_common_prefix(vec_of_strings!["flower","flow","flight"]));
    // println!("ans = {:?}", Solution::longest_common_prefix(vec_of_strings!["dog","racecar","car"]));
    // println!("ans = {:?}", Solution::longest_common_prefix(vec_of_strings!["car","car","car"]));
    // println!("ans = {:?}", Solution::int_to_roman(1994));
    // println!("ans = {:?}", Solution::int_to_roman(58));
    // println!("ans = {:?}", Solution::int_to_roman(9));
    // println!("ans = {:?}", Solution::int_to_roman(4));
    // println!("ans = {:?}", Solution::int_to_roman(5));
    // println!("ans = {:?}", Solution::int_to_roman(3));
    // println!("ans = {:?}", Solution::max_area(vec![1,8,6,2,5,4,8,3,7]));
    // println!("ans = {:?}", Solution::my_atoi("   123an".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("123".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("-123an".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("   ".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("  afsjk ".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("  9  ".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("   -123".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("   -11111111111123".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("   11111111111123".to_string()));
    // println!("ans = {:?}", Solution::my_atoi("   11111111111123".to_string()));
    // assert_eq!(Solution::my_atoi(s), 123);
    // assert_eq!(Solution::is_palindrome(12321), true);
    // assert_eq!(Solution::is_palindrome(1221), true);
    // assert_eq!(Solution::is_palindrome(121), true);
    // assert_eq!(Solution::is_palindrome(0), true);
    // assert_eq!(Solution::is_palindrome(9), true);
    // assert_eq!(Solution::is_palindrome(-121), false);
    // let mut nums1 = vec![3, 9, 10];
    // let mut nums2 = vec![-1, 3, 4];
    // let ans = Solution::find_median_sorted_arrays(nums1.clone(), nums2.clone());
    // println!( "ans = {:?}", ans);
    
    // nums1.extend(&nums2);
    // nums1.sort();
 
    // assert_eq!(Solution::median(nums1), ans);
    // let s =  "25525511135".to_string();
    // println!( "ans = {:?}", Solution::restore_ip_addresses(s));

    // println!("ans = {:?}", "123".parse::<u32>().unwrap());
    // let s =  "25525511135".to_string();
    // let st = format!( "{}.{}.{}.{}", &s[0..3], &s[3..6], &s[6..9], &s[9..] );
    // println!("st = {:?}", st);
    // let s1 = "pdwd".to_string();
    // let s2 = "wpdv".to_string();
    // let s1 = "horse".to_string();
    // let s2 = "ros".to_string();
    // let ans = Solution::min_distance(s1, s2);
    // let ans = Solution::minimum_delete_sum_1(s1, s2);

    // let k = 2;
    // let n = 14;
    // assert_eq!(Solution::super_egg_drop(2, 2), 2);
    // assert_eq!(Solution::super_egg_drop(2, 4), 3);
    // assert_eq!(Solution::super_egg_drop(1, 10), 10);
    // assert_eq!(Solution::super_egg_drop(2, 6), 3);
    // let seats = vec![1,0,0,0,0,1,0,0,0,];
    // for n in 1..20 {
    //     let ans = Solution::super_egg_drop(k, n);
    //     println!( "k = 2, (n, ans) = {:?}", (n, ans));
    // }
    // let k = 99;
    // for n in 1..20 {
    //     let ans = Solution::super_egg_drop(k, n);
    //     println!( "k = 99, (n, ans) = {:?}", (n, ans));
    // }
    // let ans = Solution::super_egg_drop(k, n);
    // // let ans = Solution::max_dist_to_closest(seats);
    // println!( "ans = {:?}", ans);

    // let A = vec![1, 4, 2];
    // let B = vec![1, 2, 4];
    // let sum = A.iter().sum()
    // let ans = Solution::max_uncrossed_lines(A, B);
    // println!( "ans = {:?}", ans);

}
