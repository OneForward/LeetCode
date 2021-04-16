// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

type Link = Option<Box<ListNode>>;

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

fn from(mut num: i32) -> Link {
    let mut vec = vec![num % 10];
    loop {
        num /= 10;
        if num == 0 { break; }
        vec.push( num % 10 );
    }
    let mut len = vec.len();

    let mut link = Some(Box::new( ListNode::new( vec[len-1]) ));
    
    loop {
        len -= 1;
        if len == 0 { break; }
        let mut new_node = ListNode::new( vec[len-1] );
        new_node.next = link.take();
        link = Some(Box::new(new_node));
    }
    link
}

fn print(mut link: &Link) {
    while let Some(node) = link {
        print!("{} -> ", node.val);
        link = &node.next;
    }
    print!("None\n");
}

struct Solution;
impl Solution {
    pub fn add_two_numbers(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // let (mut l1, mut l2) = (l1, l2);

        let mut carry = 0;
        let (mut v1, mut v2, mut sum);

        let mut dummy = Box::new(ListNode::new(0));
        let mut curr = &mut dummy;

        while l1.is_some() || l2.is_some() || carry != 0 {
            v1 = 0; v2 = 0;
            if let Some(p1) = l1 { v1 = p1.val; l1 = p1.next; }
            if let Some(p2) = l2 { v2 = p2.val; l2 = p2.next; }
            
            sum = v1 + v2 + carry;
            carry = sum / 10; sum %= 10; 
            curr.next = Some(Box::new(ListNode::new(sum)));
            curr = curr.next.as_mut().unwrap();
        }

        dummy.next
    }
}

fn main() {
    let l1 = from(0);
    let l2 = from(0);
    print(&l1);
    print(&Solution::add_two_numbers(l1, l2));
}


pub fn add_two_numbers1(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut l1 = l1;
    let mut l2 = l2;
    let mut carry = 0;
    let (mut v1, mut v2, mut sum);
    let (mut f1, mut f2) = (false, false);
    let mut vec = vec![];
    loop {
        v1 = 0; v2 = 0;
        if let Some(p1) = l1 { v1 = p1.val; l1 = p1.next; }
        else { f1 = true; }
        if let Some(p2) = l2 { v2 = p2.val; l2 = p2.next; }
        else { f2 = true; }
        if f1 && f2 { 
            if carry > 0 { vec.push( 1 ); }
            break; 
        }
        sum = v1 + v2 + carry;
        if sum >= 10 { carry = 1; sum -= 10; }
        else { carry = 0; }
        vec.push( sum );
    }

    let mut len = vec.len();
    let mut link = Some(Box::new( ListNode::new( vec[len-1]) ));      
    loop {
        len -= 1;
        if len == 0 { break; }
        let mut new_node = ListNode::new( vec[len-1] );
        new_node.next = link.take();
        link = Some(Box::new(new_node));
    }
    link
}