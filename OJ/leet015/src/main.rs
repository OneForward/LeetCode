struct Solution;

use std::collections::HashSet;
use std::collections::HashMap;
pub fn three_sum1(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut map = HashMap::new();
    for ni in nums.iter() {
        map.entry(ni).and_modify(|cnt| *cnt += 1).or_insert(1);
    }

    let mut ans = HashSet::new();
    for i in 0..nums.len() {
        for j in (i+1)..nums.len() {
            let (a, b, c) = (nums[i], nums[j    ], -(nums[i] + nums[j]));
            if let Some(&cnt) = map.get( &c ) {
                let mut elem = vec![a, b, c];
                elem.sort();
                if ((c == a || c == b) && cnt == 1) ||
                    (c == a && c == b && cnt == 2) 
                    { continue; }
                ans.insert(elem);
                    
                
            }
        }
    }

    ans.into_iter().collect()
}


pub fn three_sum2(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut nums = nums.clone();
    nums.sort();
    let mut ans = HashSet::new();
    // println!("nums = {:?}", nums);
    let (i0, found0) = lfind(&nums, 0, 0, nums.len());
    
    let mut j0 = i0;
    while j0 < nums.len() && nums[j0] == 0 { j0 += 1; }

    if found0 {
        // at least three 0s , [0, 0, 0]
        if j0 - i0 >= 3 {
            ans.insert(vec![0, 0, 0]);
        }

        // [neg, 0, pos]
        for i in 0..i0 {
            let (j, found) = lfind(&nums, -nums[i], j0, nums.len());
            if found { ans.insert(vec![nums[i], 0, nums[j]]); }
        }
    }

    // [neg, neg, pos] or [neg, pos, pos]
    for i1 in 0..i0 {
        for i2 in (i1+1)..i0 {
            let (j, found) = lfind(&nums, -nums[i1]-nums[i2], j0, nums.len());
            if found { ans.insert(vec![nums[i1], nums[i2], nums[j]]); }
        }
    }
    for i1 in j0..nums.len() {
        for i2 in (i1+1)..nums.len() {
            let (j, found) = lfind(&nums, -nums[i1]-nums[i2], 0, i0);
            if found { 
                // println!("(i1, i2) = {:?}", (i1, i2));
                ans.insert(vec![nums[j], nums[i1], nums[i2]]); }
        }
    }
    ans.into_iter().collect()
}

impl Solution {

    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let len = nums.len();
        if len < 3 { return vec![]; }

        let mut nums = nums.clone();
        nums.sort();

        let mut ans = vec![];
        let (mut i, mut j);

        for k in 0..len-2 {
            if k > 0 && nums[k] == nums[k-1] { continue; }
            if nums[k] + nums[k+1] + nums[k+2] > 0 { continue; }
            if nums[k] + nums[len-1] + nums[len-2] < 0 { continue; }

            i = k + 1; j = len - 1;            
            while i < j {

                if i > k + 1 && nums[i] == nums[i-1] { i += 1; continue; }
                if j < len - 1 && nums[j] == nums[j+1] { j -= 1; continue; }

                let s = nums[i] + nums[j] + nums[k];

                if s < 0 { i += 1; }
                else if s > 0 { j -= 1; }
                else { 
                    ans.push(vec![nums[k], nums[i], nums[j]]);
                    i += 1; j -= 1;               
                }
            }
        }
        ans
    }
}

fn lfind( arr: &Vec<i32>, key: i32 , mut lft: usize, mut rht: usize) -> (usize, bool) {
    // 如果找到，返回最左边的索引，如果没找到，返回仅高于它的值索引
    while lft < rht {
        let mid = (lft + rht) / 2;
        if arr[mid] >= key { rht = mid; }
        else { lft = mid + 1; }
    }
    if lft < arr.len() && arr[lft] == key { (lft, true) }
    else { (lft, false) }
}
fn main() {
    // let test = vec![-2, 0,0,0];
    // println!("lfind = {:?}", lfind(&test, -3));
    let mut nums = vec![];
    println!("ans = {:?}", Solution::three_sum(nums));
    println!("Hello, world!");
}
