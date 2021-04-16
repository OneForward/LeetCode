
struct Solution;

use std::cmp::min;
impl Solution {
    pub fn min_cost_to_move_chips(chips: Vec<i32>) -> i32 {
        let (mut odd, mut even) = (0, 0);
        for pos in chips {
            match pos & 1  {
                0 => odd += 1,
                1 => even += 1,
                _ => {}
            }
        }
        min(odd, even)
    }
}

fn main() {
    let chips = vec![2, 2, 2, 3, 3];
    println!("ans = {:?}", Solution::min_cost_to_move_chips(chips));
}
