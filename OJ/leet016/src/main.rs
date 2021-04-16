struct Solution;
impl Solution {

    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums.clone();
        nums.sort();

        let mut ans = 0x7fff_ffffi32;
        let (mut update_i, mut update_j );
        let (mut i, mut j);
        
        'outer: for k in 0..nums.len() {
            if k > 0 && nums[k] == nums[k-1] { continue; }

            i = k + 1; j = nums.len()-1;            
            while i < j {
                update_i = false; update_j = false;

                let s = nums[i] + nums[j] + nums[k] - target;

                if s.abs() < ans.abs() { ans = s; }

                if s < 0 { update_i = true; }
                else if s > 0 { update_j = true; }
                else { break 'outer; }

                if update_i { let ni = nums[i]; while i < j && nums[i] == ni { i += 1; }} 
                if update_j { let ni = nums[j]; while i < j && nums[j] == ni { j -= 1; }}
            }
        }
        ans + target
    }
}

fn main() {
    // let test = vec![-2, 0,0,0];
    // println!("lfind = {:?}", lfind(&test, -3));
    let mut nums = vec![-1, 2, 1,-4];
    let target = 1;
    println!("ans = {:?}", Solution::three_sum_closest(nums, target));
    println!("Hello, world!");
}
