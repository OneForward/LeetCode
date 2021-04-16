struct Solution;
impl Solution {
    pub fn convert(s: String, n: i32) -> String {
        // 0 ms
        let n = n as usize;
        if n == 1 { return s; }

        let mut ans = vec![vec![]; n];
        let mut pos = 0;
        enum DIRECTION { UP, DOWN };
        let mut direction = DIRECTION::DOWN;
        for si in s.into_bytes() {
            ans[pos].push(si);
            match direction {
                DIRECTION::DOWN => { 
                    if pos == n-1 { pos -= 1; direction = DIRECTION::UP; } 
                    else { pos += 1; } 
                },
                DIRECTION::UP => { 
                    if pos == 0 { pos += 1; direction = DIRECTION::DOWN;} 
                    else { pos -= 1; } 
                },
            }
        }
        let rst = ans.into_iter().flat_map( |vec| vec.into_iter() ).collect();
        String::from_utf8(rst).unwrap()
    }
}
fn main() {
    let s = "LEETCODEISHIRING".to_string();
    let n = 1;
    println!("ans = {:?}", Solution::convert(s, n) );
}
