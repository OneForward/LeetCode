#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(unused_mut)]
#![allow(dead_code)]
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn  median(vec: Vec<i32>) -> f64 { 
        let len = vec.len();
        if len % 2 == 0 {
            (vec[len/2] + vec[len/2-1]) as f64 / 2.0
        }
        else {
            vec[len/2] as f64
        }
    }
    pub fn find_median_sorted_arrays(A: Vec<i32>, B: Vec<i32>) -> f64 {
        // 0ms leet004, O(log(min(n, m)))
        // 思路： median 是第 half = (n+m)/2 个数, 设此时 A 供给了 Alft 个数, B 供给了 Blft 个数
        // 则有 Alft + Blft == half, 并且 A[Alft+1] >= B[0..Blft], B[Blft+1] >= A[..Alft]
        // 因此对 Alft 二分搜索即可

        if A.len() > B.len() { return Self::find_median_sorted_arrays(B, A); }
        if A.len() == 0 { return Self::median(B); }
        let half = (A.len() + B.len()) / 2;
        
        println!("half = {:?}", half);
        let (mut lft, mut rht) = (0, A.len()+1);
        let (mut Alft, mut Blft) = (0, 0);
        while lft < rht {
            Alft = (lft + rht) / 2;
            Blft = half - Alft;
            println!("Alft = {:?}, Blft = {:?}", Alft, Blft);
            if Alft == 0 {
                if A[Alft] < B[Blft-1] { lft = Alft + 1; }
                else { break; }
            }
            else if Alft == A.len() {
                if A[Alft-1] > B[Blft] { rht = Alft; }
                else { break; }
            }
            else {
                if A[Alft] < B[Blft-1] { lft = Alft + 1; }
                else if A[Alft-1] > B[Blft] { rht = Alft; }
                else { break; }
            }
        }
        println!("Alft = {:?}, Blft = {:?}", Alft, Blft);
        if (A.len() + B.len()) % 2 == 0 {
            let (mlft, mrht);
            if Alft == 0 {
                mlft = B[Blft-1];
                mrht = if Blft == B.len() { A[Alft] }
                        else { min(A[Alft], B[Blft]  ) };
            }
            else if Alft == A.len() {
                mlft  = if Blft == 0 { A[Alft-1] }
                        else { max( A[Alft-1], B[Blft-1]) };
                mrht = B[Blft];
            }
            else {
                mlft = max(A[Alft-1], B[Blft-1]);
                mrht = min(A[Alft], B[Blft]);
            }
            (mlft + mrht) as f64 / 2.0 
        }
        else {
            if Alft == A.len() { B[Blft] as f64 }
            else { min(A[Alft], B[Blft]) as f64 }
        }
    }
    pub fn min_distance072(word1: String, word2: String) -> i32 {
        // 4ms , leet072
        let mut d = vec![ vec![ 0; word2.len() + 1 ]; word1.len() + 1] ;
        let (word1, word2) = ( word1.into_bytes(), word2.into_bytes() );
        for i in 0..=word2.len() { d[0][i] = i;  }
        for i in 0..=word1.len() { d[i][0] = i;  }
        for (i, s1) in word1.iter().enumerate() {
            for (j, s2) in word2.iter().enumerate() {
                if s1 == s2 { d[i+1][j+1] = d[i][j]; }
                else { d[i+1][j+1] = 1 + min( d[i+1][j], min (d[i][j+1], d[i][j] ) ); }
            }
        }
        // println!("d = {:?}", d);
        d[word1.len()][word2.len()] as i32
    }
    pub fn min_distance(s1: String, s2: String) -> i32 {
        // 0ms, leet583
        let mut d = vec![ vec![ 0; s2.len() + 1 ]; s1.len() + 1] ;
        let (s1, s2) = ( s1.into_bytes(), s2.into_bytes() );
        for (i, s1) in s1.iter().enumerate() {
            for (j, s2) in s2.iter().enumerate() {
                if s1 == s2 { d[i+1][j+1] = 1 + d[i][j]; }
                else { d[i+1][j+1] = max( d[i+1][j], d[i][j+1] ); }
            }
        }
        (s1.len() + s2.len() - d[s1.len()][s2.len()]) as i32
    }

    pub fn minimum_delete_sum_1(s1: String, s2: String) -> i32 {
        // 12ms, 100%, leet712
        #[derive(Clone, Debug, PartialEq)]
        enum DIRECT {
            Level, Vertical, Tilted, Nothing
        }
        type Elem = (i32, DIRECT, i32);

        let mut d = vec![ vec![ (0, DIRECT::Nothing, 0); s2.len() + 1 ]; s1.len() + 1] ;
        let (s1, s2) = ( s1.into_bytes(), s2.into_bytes() );
        fn max((n1, _, s1): &Elem, (n2, _, s2): &Elem) -> Elem {
            if n1 > n2 || ( n1 == n2 && s1 > s2) { (*n1, DIRECT::Level, *s1) }
            else { (*n2, DIRECT::Vertical, *s2) }
        }
        for (i, s1) in s1.iter().enumerate() {
            for (j, s2) in s2.iter().enumerate() {
                if s1 == s2 { d[i+1][j+1] = (1 + d[i][j].0, DIRECT::Tilted, d[i][j].2 + *s1 as i32); }
                else { d[i+1][j+1] = max( &d[i+1][j], &d[i][j+1] ); }
            }
        }
        // for di in d[1..].iter() {
        //     println!("{:?}", &di[1..]);
        // }
        let mut common = vec![];
        let (mut i, mut j) = (s1.len(), s2.len());
        loop {
            match d[i][j].1 {
                DIRECT::Tilted => {
                    common.push(s1[i-1] as i32);
                    i -= 1; j -= 1;
                },
                DIRECT::Level => { j -= 1; }
                DIRECT::Vertical => { i -= 1; }
                _ => { break; }
            }
        }
        // let s = String::from_utf8(common.iter().map(|x| *x as u8).collect());
        // println!("s = {:?}", s);
        let total:i32 = s1.iter().map(|x| *x as i32).sum::<i32>() + 
                        s2.iter().map(|x| *x as i32).sum::<i32>();
        let common: i32 = common.iter().sum();
        total - 2 * common    
    }

    pub fn minimum_delete_sum(s1: String, s2: String) -> i32 {
        // 4ms, 100%, leet712
        let mut d = vec![ vec![0; s2.len() + 1 ]; s1.len() + 1] ;
        let (s1, s2) = ( s1.into_bytes().into_iter().map(|x| x as i32).collect::<Vec<i32>>(), 
                         s2.into_bytes().into_iter().map(|x| x as i32).collect::<Vec<i32>>() );
        for i in 0..s1.len() { d[i+1][0] = d[i][0] + s1[i];}
        for i in 0..s2.len() { d[0][i+1] = d[0][i] + s2[i];}
        for (i, s1) in s1.iter().enumerate() {
            for (j, s2) in s2.iter().enumerate() {
                if s1 == s2 { d[i+1][j+1] = d[i][j] ;}
                else { d[i+1][j+1] = min( d[i+1][j] + *s2, d[i][j+1] + *s1 ); }
            }
        }
        d[s1.len()][s2.len()]
    }

    pub fn restore_ip_addresses(s: String) -> Vec<String> {
        let mut ans = vec![];
        if s.len() < 4 || s.len() > 12 { return ans; }

        // let mut index = vec![];
        // fn dfs(s: &String, ans: &mut Vec<String>, index: &mut Vec<usize>, 
        //     L: usize, currL: usize, cnt: usize) {
        //     if cnt == 0 { ans.push( 
        //         format!( "{}.{}.{}.{}", &s[0..3], &s[3..6], &s[6..9], &s[9..] ) ) 
        //     }
        //     for len in 1..=3 {
        //         if cnt <= L - (currL + len) && L - (currL + len) <= 3* cnt {
        //             index.push(len);
        //             let mut tmp = ans;
        //             dfs(&s, &mut tmp, &mut index, s.len(), 0, 4);
        //         }
        //     }
        // }

        // dfs(&s, &mut ans, &mut index, s.len(), 0, 4);

        ans 
    }
    
    pub fn max_uncrossed_lines(a: Vec<i32>, b: Vec<i32>) -> i32 {
        // 0ms, leet1035
        let mut d = vec![ vec![ 0; b.len() + 1 ]; a.len() + 1] ;
        for (i, ai) in a.iter().enumerate() {
            for (j, bi) in b.iter().enumerate() {
                if ai == bi { d[i+1][j+1] = 1 + d[i][j]; }
                else { d[i+1][j+1] = max( d[i+1][j], d[i][j+1] ); }
            }
        }
        d[a.len()][b.len()] as i32
    }
}

fn main() {
    println!( "ans = {:?}", Solution::find_median_sorted_arrays(vec![1,2], vec![-1,3]));
    
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

    // println!( "ans = {:?}", ans);


    // let A = vec![1, 4, 2];
    // let B = vec![1, 2, 4];
    // let sum = A.iter().sum()
    // let ans = Solution::max_uncrossed_lines(A, B);
    // println!( "ans = {:?}", ans);

}

