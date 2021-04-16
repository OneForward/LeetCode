
struct Node{
    elem: i32
}

struct S<'a> {
    node: Option<&'a mut Node>
}

fn f<'a>(s: &'a mut S) -> Option<&'a mut i32> {
    // s: &mut S
    // s.node: Some(&mut Node)
    // ret: Some(&mut i32)
    s.node.map(|node| {
        &mut node.elem
    })
}
fn main() {
    let mut node = Node {elem: 1};
    let mut s = S {
        node: Some(&mut node)
    };
    let val = f(&mut s);
    println!("val = {:?}", val);
    println!("Hello, world!");
}


