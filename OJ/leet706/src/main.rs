pub struct Solution;
fn set_bits(mut n: u32) -> u32 {
    let mut cnt = 0u32;
    while n != 0 {
        if n % 2 == 1 { cnt += 1; }
        n >>= 1;
    }
    cnt
}

impl Solution {
    pub fn count_prime_set_bits(l: i32, r: i32) -> i32 {
        let mut cnt = 0i32;
        for i in l..=r {
            cnt += match set_bits(i as u32) {
                2 | 3 | 5 | 7 | 11 | 13 | 17 | 19 => 1,
                _ => 0,
            }
        }
        cnt 
    }
}

fn main() {
    #[allow(non_snake_case)]
    let (L, R) = (10, 15);
    println!("count_prime_set_bits({}, {}) = {:?}",
             L, R, Solution::count_prime_set_bits(L, R));
}