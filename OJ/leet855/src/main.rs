#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(unused_mut)]
#![allow(dead_code)]

struct ExamRoom {
    len: usize,
    
}

impl ExamRoom {

    fn new(N: i32) -> Self {
        ExamRoom{}
    }
    
    fn seat(&self) -> i32 {
        0
    }
    
    fn leave(&self, p: i32) {
        
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * let obj = ExamRoom::new(N);
 * let ret_1: i32 = obj.seat();
 * obj.leave(p);
 */
fn main() {
    let N = 10;
    let room = ExamRoom::new(N);
    println!("seat: {:?}", room.seat());
    println!("seat: {:?}", room.seat());
    println!("seat: {:?}", room.seat());
    println!("seat: {:?}", room.seat());
    println!("leave: {:?}", room.leave(4));
    println!("seat: {:?}", room.seat());
    println!("Hello, world!");
}
