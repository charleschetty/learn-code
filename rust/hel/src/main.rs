// use std::str::pattern::StrSearcher;

use std::{fmt::Display};

fn main(){
    let fi=Point::new(3, 2);
    println!("{}",fi.x);
    let st=fi.summarize();
    println!("{}",st);
    fi.show();
    let asd=[1,3,2,10];
    let aa=largest(&asd);
    println!("{}",asd.len());
    println!("fuck");
}


fn largest<T:PartialOrd+Copy>(list:&[T])->T{
    let mut larg=list[0];
    for &item in list{
        if item>larg{
            larg=item;
        }
    }
    return larg;
}

fn longets<'a>(x:&'a str,y:&'a str)->&'a str{
    if x.len()>y.len(){
        x
    }
    else{
        y
    }
}
pub trait Summary{
    fn summarize(&self)->String{
        String::from("read more")
    }

}

struct Point<T> where T:Display{
    x:T,
    y:T,
}

impl<T:Display> Summary for Point<T>{
    fn summarize(&self)->String{
        String::from("point")
    }
}


impl<T:Display> Point<T>{
    fn new(x1:T,y1:T)->Point<T>{
        Point{x:x1,y:y1}
    }

    fn show(&self){
        println!("x:{},y:{}",self.x,self.y);
    }
}