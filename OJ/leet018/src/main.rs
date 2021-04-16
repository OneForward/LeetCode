struct Solution;

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        if nums.len() < 4 { return vec![]; }

        let mut nums = nums.clone();
        nums.sort();

        let mut ans = vec![];
        let len = nums.len();
        for i in 0..len-3 {
            if i > 0 && nums[i] == nums[i-1] { continue; }
            if nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target {  continue; }
            if nums[i] + nums[len-1] + nums[len-2] + nums[len-3] < target {  continue; }

            Self::three_sum(&nums, i+1, target - nums[i], &mut ans);
            
        }
        ans
    }

    pub fn three_sum(nums: &Vec<i32>, start: usize, target: i32, ans: &mut Vec<Vec<i32>> ) {
        let (mut update_i, mut update_j );
        let (mut i, mut j);
        
        for k in start..nums.len()-2 {
            if k > start && nums[k] == nums[k-1] { continue; }
            i = k + 1; j =  nums.len()-1;            
            while i < j {
                update_i = false; update_j = false;

                let s = nums[i] + nums[j] + nums[k];

                if s < target { update_i = true; }
                else if s > target { update_j = true; }
                else { ans.push(vec![nums[start-1], nums[k], nums[i], nums[j]]);
                    update_i = true; update_j = true;
                }

                if update_i { let ni = nums[i]; while i < j && nums[i] == ni { i += 1; }} 
                if update_j { let ni = nums[j]; while i < j && nums[j] == ni { j -= 1; }}
            }
        }
    }
}

fn main() {    
    let mut nums = vec![1,0,-1,0,-2,2];
    let target = 0;
    println!("ans = {:?}", Solution::four_sum(nums, target));
    println!("Hello, world!");
    println!("Hello, world!");
}
