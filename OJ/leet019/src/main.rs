#![allow(non_snake_case)]
#![allow(unused_variables)]
#![allow(unused_mut)]
#![allow(dead_code)]
#![allow(unused_macros)]
struct Solution;
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


fn print(mut link: &Link) {
    while let Some(node) = link {
        print!("{} -> ", node.val);
        link = &node.next;
    }
    print!("None\n");
}

type Link = Option<Box<ListNode>>;
impl Solution {
    pub fn remove_nth_from_end(mut head: Link, n: i32) -> Link {
        // 0ms, leet019
        let mut prev_head = Box::new(ListNode::new(0));
        prev_head.next = head;

        let mut p1 = &mut prev_head as *mut Box<ListNode>;
        let mut p2 = prev_head.next.as_ref().unwrap();
 
        for _ in 0..n-1 {
            p2 = p2.next.as_ref().unwrap();
        }

        unsafe {
            while p2.next.is_some() { 
                p1 = (*p1).next.as_mut().unwrap();
                p2 = p2.next.as_ref().unwrap();
            }
    
            let next = (*p1).next.take().unwrap();
            (*p1).next = next.next;
        }
        
        return prev_head.next
    }
    
    pub fn remove_nth_from_end1(mut head: Link, n: i32) -> Link {
        // 0ms, leet019
        let (mut p1, mut p2) = (&mut None as *mut Link, &head as *const Link);
        let mut cnt = 0;
        unsafe {
            while (*p2).is_some() {
                cnt += 1;
                p2 = &(*p2).as_ref().unwrap().next;
                if cnt > n {
                    p1 = &mut head; break;
                }
            }
            while (*p2).is_some() {
                p1 = &mut (*p1).as_mut().unwrap().next;
                p2 = &(*p2).as_ref().unwrap().next;
            }
            if (*p1).is_none() { head = head.unwrap().next;  }
            else {
                let mut node = (*p1).as_mut().unwrap();
                let mut next = node.next.take().unwrap();
                node.next = next.next;
            }
        }
        head
    }
    pub fn reverse_list(head: Link) -> Link {
        // 0ms, leet206, 动态规划
        fn rev(curLink: Link, prevLink: Link) -> Link {
            if let Some(mut p) = curLink {
                let nextLink = p.next;
                p.next = prevLink;
                return rev(nextLink, Some(p));
            }
            else { return prevLink; }
        }
        return rev(head, None);
    }

    pub fn reverse_list1(head: Link) -> Link {
        // 0ms, leet206
        let (mut cur, mut last);
        match head {
            Some(mut p) => {
                cur = p.next; p.next = None; last = Some(p);
            },
            None => { return head; },
        }
        while let Some(mut pcur) = cur {
            cur = pcur.next;
            pcur.next = last;
            last = Some(pcur);
        }
        last
    }
}
fn main() {
    let mut head = Some(Box::new(ListNode::new(0))); let mut p = head.as_mut().unwrap();
    // for i in 1..10 {
    //     p.next = Some(Box::new(ListNode::new(i)));
    //     p = p.next.as_mut().unwrap();
    // }
    print(&head);
    print(&Solution::remove_nth_from_end(head, 1));
    // print(&Solution::reverse_list(head));
}
