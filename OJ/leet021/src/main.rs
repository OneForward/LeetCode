


// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

type Link =  Option<Box<ListNode>>;

fn from(vec: &Vec<i32>) -> Link {
    let mut head = Box::new(ListNode::new(0));
    let mut node = &mut head; 
    
    for &vi in vec.iter() {
        node.next = Some(Box::new(ListNode::new(vi)));
        node = node.next.as_mut().unwrap();
    }
    return head.next;
}

struct Solution;
impl Solution {
    pub fn merge_two_lists(mut l1: Link, mut l2: Link) -> Link {
        // leet021, 0ms
        let mut head = Box::new(ListNode::new(0));
        let mut node = &mut head; 
        
        while l1.is_some() && l2.is_some() {
            
            if l1.as_ref().unwrap().val < l2.as_ref().unwrap().val {
                node.next = l1.take();
                l1 = node.next.as_mut().unwrap().next.take();
            }
            else {
                node.next = l2.take();
                l2 = node.next.as_mut().unwrap().next.take();
            }
            node = node.next.as_mut().unwrap();
        }
        while l1.is_some()  {
            node.next = l1.take();
            l1 = node.next.as_mut().unwrap().next.take();
            node = node.next.as_mut().unwrap();
        }
        while l2.is_some()  {
            node.next = l2.take();
            l2 = node.next.as_mut().unwrap().next.take();
            node = node.next.as_mut().unwrap();
        }
        return head.next
    }
}

fn main() {
    let mut x = &vec![1,2,3];
    let y = &vec![1,1,2,2,3];

    let l1 = from(&x);
    let l2 = from(&y);
    println!("{:?}", Solution::merge_two_lists(l1, l2));
}