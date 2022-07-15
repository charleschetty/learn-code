// use num::complex::Complex;

fn main() {
    // println!("Hello, world!");
    // let x = "hellp";
    // let (a, mut c): (bool, bool) = (true, false);
    // println!("a{},b{}", a, c);
    // println!("{}", x);
    // let xa=(-21.0_f32).sqrt();
    // println!("{}",xa);
    // for i in 1..=5{
    //     println!("{}",i);
    //
    // }
    // let r1=Complex{re:23.1,im:-2.1};
    // let r2=Complex::new(111.2,1.21);
    // let res=r1+r2;
    // println!("{}+{}i",res.re,res.im)
    // let y = {
    //     let x = 21;
    //     x + 1
    // };
    // println!("{}", y);
    // fun1(32, 3.3);
    // fun2(0.9);
    // println!("{}", fun2(0.8));
    // let mut x1=String::from("hellpo");
    // x1.push_str("fuxa ");
    // println!("{}",x1);
    // let st1:&str="hel";
    // let _y=st1;
    // println!("{}",st1);
    // let s1=String::from("h1");
    // let s2=s1.clone();
    // println!("{}",s2);
    //
    let s = String::from("hello");
    // takeownership(s);
    // println!("{}",s);
    let x = 5;
    let y = &x;
    assert_eq!(5, *y);
    println!("{}", cla_len(&s));
    
}
fn cla_len(str1: &String) -> usize {
    str1.len()
}
fn takeownership(somestring: String) {
    println!("{} somestring", somestring);
}

// fn fun1(x: i32, y: f64) {
//     println!("x:{}", x);
//     println!("y:{}", y);
// }
//
// fn fun2(x: f64) -> f64 {
//     if x > 1.0 {
//         return x + 10.0;
//     }
//     x - 10.0
// }
