struct Solution;

impl Solution {
    pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        let mut index = vec![9999; 1005];
        let mut cnt = vec![0; arr2.len()];
        for (i, ai) in arr2.iter().enumerate() {
            index[*ai as usize] = i;
        }
        
        let mut rest = Vec::new();
        for ai in arr1.into_iter() {
            if index[ai as usize] == 9999 {
                rest.push(ai);
            }
            else {
                cnt[index[ai as usize]] += 1;
            }
        }

        rest.sort();

        let mut ans = Vec::new();
        for (i, ci) in cnt.into_iter().enumerate() {
            for _ in 0..ci {
                ans.push(arr2[i]);
            }
        }
        for ri in rest.into_iter() {
            ans.push(ri);
        }
        ans
    }
}

fn main() {
    let arr1 = vec![2,3,1,3,2,4,6,7,9,2,19];
    let arr2 = vec![2,1,4,3,9,6];
    println!(" = {:?}", Solution::relative_sort_array(arr1, arr2));
}