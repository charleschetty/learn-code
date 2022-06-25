mod font_of_hou{
    pub mod hosting{
        pub fn show(){
            println!("host");
        }

        fn show1(){
            println!("host1");
        }
    }

    mod server{
        fn show(){
            println!("serbve");
        }
    }
}

pub fn eat_At_res(){
    font_of_hou::hosting::show();
}