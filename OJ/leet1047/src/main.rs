use std::collections::LinkedList;
use std::mem;

struct Solution;

type Link<T> = Option<Box<Node<T>>>;

#[derive(Debug)]
struct Node<T> {
    element: T,
    prev: Link<T>,
    next: Link<T>,
}


#[derive(Debug)]
struct List<T> {
    head: Link<T>,
    tail: Link<T>,
}

impl<T> Node<T> {
    fn new(element: T) -> Self {
        Node {
            next: None,
            prev: None,
            element,
        }
    }

    fn into_element(self: Box<Self>) -> T {
        self.element
    }
}

impl<T> List<T> {
    fn new() -> Self {
        List { head: None, tail: None }
    }

    fn push_back_node(&mut self, mut node: Box<Node<T>>) {
        node.next = None;
        node.prev = mem::replace(&mut self.tail, None);
        let node = Some(node);

        match mem::replace(&mut self.tail, None) {
            None => self.head = node,
            // Some(mut tail) => tail.as_mut().next = node,
            Some(mut tail) => tail.next = node,
        }
        self.tail = node;
    }


    fn push_back(&mut self, elt: T) {
        self.push_back_node( Box::new( Node::new(elt) ));
    }
}
use std::fmt::{self, Formatter, Display};
impl<T: Display> Display for List<T> {
    fn fmt(&self, f: &mut Formatter) -> fmt::Result {
        let mut p = &self.head;
        let mut s = String::new();
        while true {
            match p {
                Some(node) => { s += &format!(" -> {}", node.element); p = &node.next;}
                None => {},
            }
        }
        write!(f, "{}", s)
        // write!(f, "{}: {:.3}°{} {:.3}°{}",
        //        self.name, self.lat.abs(), lat_c, self.lon.abs(), lon_c)
    }
}


// impl Solution {
//     pub fn remove_duplicates(s: String) -> String {
//         let s = s.into_bytes();
//         let list: LinkedList<u8> = LinkedList::new();
//         for si in s {
//             list.push_back(si);
//         }

//         end = list.back();
//         while true {

//         }
//         "".to_string()
//     }
// }

fn main() {
    let mut L = List::new();
    for i in 0..5 {
        L.push_back(i)
    }
    println!("L = {:?}", L);
    // println!("ans = {:?}", Solution::remove_duplicates(s));
}