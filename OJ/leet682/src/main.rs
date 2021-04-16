#![allow(non_snake_case)]

struct Solution;
impl Solution {
    pub fn cal_points(ops: Vec<String>) -> i32 {
        let mut Int = Vec::<i32>::new();
        for op in ops.iter() {
            match op.as_str() {
                "C" => { Int.pop(); }
                "D" => { Int.push( 2 * Int.last().unwrap()); }
                "+" => { Int.push( Int[Int.len()-2] + Int[Int.len()-1]); }
                s => { Int.push(String::from(s).parse::<i32>().unwrap()); }
            }
        }
        
        Int.iter().sum::<i32>() 
    }
}

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

fn main() {
    let ops = vec_of_strings!["5","-2","4","C","D","9","+","+"];
    println!("ans = {:?}", Solution::cal_points(ops) );
}
