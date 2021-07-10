// leet981
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]


macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}



use std::{collections::HashMap, default};
use std::cmp::{max, min};

#[derive(Default)]
struct TimeMap {
    M: HashMap<String, Vec<(i32, String)>>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TimeMap {

    /** Initialize your data structure here. */
    fn new() -> Self {
        TimeMap::default()
    }
    
    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.M.entry(key).or_insert(Vec::new()).push((timestamp, value));
    }
    
    fn get(&self, key: String, timestamp: i32) -> String {
        let mut ans = String::new();
        if let Some(v) = self.M.get(&key) {
            let (mut lft, mut rht) = (0, v.len());
            while lft < rht {
                let mid = (lft + rht) / 2;
                if v[mid].0 > timestamp { rht = mid; }
                else {lft = mid + 1;}
            }
            if lft > 0 { ans = v[lft-1].1.clone(); }
        }
        ans
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */

fn main() {
    let mut kv = TimeMap::new();
    kv.set("foo".to_string(), "bar".to_string(), 1); // 存储键 "foo" 和值 "bar" 以及时间戳 timestamp = 1   
    println!("{:?}", kv.get("foo".to_string(), 1));  // 输出 "bar"   
    println!("{:?}", kv.get("foo".to_string(), 3)); // 输出 "bar" 因为在时间戳 3 和时间戳 2 处没有对应 "foo" 的值，所以唯一的值位于时间戳 1 处（即 "bar"）   
    kv.set("foo".to_string(), "bar2".to_string(), 4);
    println!("{:?}", kv.get("foo".to_string(), 4)); // 输出 "bar2"   
    println!("{:?}", kv.get("foo".to_string(), 5)); // 输出 "bar2"   
}
