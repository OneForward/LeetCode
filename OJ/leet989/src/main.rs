struct Solution;

impl Solution {
    pub fn plus_one(mut arr: Vec<i32>) -> Vec<i32> {
        // 0 ms - leet066
        Self::add_to_array_form(arr, 1)
    }

    pub fn add_binary(a: String, b: String) -> String {
        // 0 ms - leet067
        if a.len() < b.len() { return Self::add_binary(b, a); }

        let a: Vec<u8> = a.into_bytes().into_iter().rev().map(|x| x - '0' as u8).collect();
        let b: Vec<u8> = b.into_bytes().into_iter().rev().map(|x| x - '0' as u8).collect();

        let mut ans = vec![0; a.len()+1];
        let mut carry = 0;
        for i in 0..b.len() {
            ans[i] = a[i] + b[i] + carry;
            carry = ans[i] / 2; ans[i] %= 2; 
        }
        for i in b.len()..a.len() {
            ans[i] = a[i] + carry;
            carry = ans[i] / 2; ans[i] %= 2; 
        }
        ans[a.len()] = carry;
        
        let rst;
        if carry > 0 { rst = &ans[..] }
        else { rst = &ans[..a.len()] }
        String::from_utf8(rst.into_iter().rev().map(|x| x + '0' as u8).collect()).unwrap()
    }

    pub fn add_to_array_form(mut arr: Vec<i32>, mut k: i32) -> Vec<i32> {
        // 16ms 70%
        for i in (0..arr.len()).rev() {
            arr[i] += k % 10; k /= 10;
            if arr[i] >= 10 {
                k += 1; arr[i] -= 10; 
            }
            if k == 0 { break; }
        }
        let mut pre_arr = vec![];
        while k > 0 { 
            pre_arr.push(k % 10); k /= 10;
        }
        pre_arr.into_iter().rev().chain( arr.into_iter() ).collect()
    }
}

fn main() {
    let a = vec![9,9,9];
    let k = 1;
    
    println!("ans = {:?}", Solution::add_to_array_form(a.clone(), k));
    println!("ans = {:?}", Solution::plus_one(a));

    let a = "1010".to_string();
    let b = "1011".to_string();
    println!("ans = {:?}", Solution::add_binary(a, b));
}
