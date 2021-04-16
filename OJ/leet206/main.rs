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

  fn print(&self) {
      
  }
}

type Link = Option<Box<ListNode>>;
impl Solution {
    pub fn reverse_list(head: Link) -> Link {
        // 
        fn rev(cur: Link, prev: Link) -> Link {
            if let Some(mut p) = cur {
                let nextNode = p.next;
                p.next = prev;
                return rev(nextNode, Some(p));
            }
            else { return prev; }
        }
        return rev(head, None);
    }
}

fn main() {
    // let sol = Solution;
    let head = ListNode { 0i32, None};
    // head.next = new(1);
    let bx = Box::new(head);
    println!("bx.val = {:?}", bx.val);
    println!("head.next = {:?}", head.next);
    
    // sol.reverse_list()
}