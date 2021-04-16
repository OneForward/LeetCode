struct Solution;
impl Solution {
    // 0 ms
    pub fn multiply(num1: String, num2: String) -> String {
        if num1 == "0" || num2 == "0" { return "0".to_string(); }
        let vec1: Vec<u8> = num1.into_bytes().into_iter().rev().map( |b| b - '0' as u8 ).collect();
        let vec2: Vec<u8> = num2.into_bytes().into_iter().rev().map( |b| b - '0' as u8 ).collect();
        
        let len = vec1.len() + vec2.len();
        let mut ans = vec![0; len];
        let mut carry = 0;
        for (i1, v1) in vec1.iter().enumerate() {            
            carry = 0;
            for (i2, v2) in vec2.iter().enumerate() {
                ans[i1 + i2] += v1 * v2 + carry;
                carry = ans[i1 + i2] / 10;
                ans[i1 + i2] %= 10;
            }
            ans[i1 + vec2.len()] += carry;
        }
    
        let rst;
        if carry > 0 {
            rst = ans.iter().rev().map( |x| x + '0' as u8 ).collect();
        }
        else {
            rst = ans[..len-1].iter().rev().map( |x| x + '0' as u8 ).collect();
        }
        String::from_utf8(rst).unwrap()
    }
}
fn main() {
    let s1 = "10".to_string();
    let s2 = "9".to_string();
    println!("ans = {:?}", Solution::multiply(s1, s2));
}
