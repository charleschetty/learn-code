mod Derivative;
mod integ;

use std::{vec, f64::consts::PI};
use Derivative::{three_point_dec, Formulas};
use crate::Derivative::five_point_dec;
use crate::integ::Gaussian;
use crate::integ::Gaussian_Double;
use crate::integ::com_midp_rul;
use crate::integ::com_trap_rule;
use crate::integ::comp_simpson_rule;
use crate::integ::gaussiancof;
use crate::integ::romberg;



fn main() {
    // let x_0=[2.1,2.2,2.3,2.4,2.5,2.6];
    // let fx0=[-1.709847,-1.373823,-1.119214,-0.9160143,-0.7470223,-0.6015966];
    // let fd0=five_point_dec(x_0[0..5].to_vec(),fx0[0..5].to_vec(), Formulas::First);
    // let fd1=five_point_dec(x_0[1..6].to_vec(),fx0[1..6].to_vec(), Formulas::First);
    // let fd2=five_point_dec(x_0[0..5].to_vec(),fx0[0..5].to_vec(), Formulas::Middle);
    // let fd3=five_point_dec(x_0[1..6].to_vec(),fx0[1..6].to_vec(), Formulas::Middle);
    // let fd4=five_point_dec(x_0[0..5].to_vec(),fx0[0..5].to_vec(), Formulas::End);
    // let fd5=five_point_dec(x_0[1..6].to_vec(),fx0[1..6].to_vec(), Formulas::End);

    // println!("f'({}):{}",x_0[0],fd0);
    // println!("f'({}),{}",x_0[1],fd1);
    // println!("f'({}):{}",x_0[2],fd2);
    // println!("f'({}):{}",x_0[3],fd3);
    // println!("f'({}):{}",x_0[4],fd4);
    // println!("f'({}):{}",x_0[5],fd5);


    // println!("{}",comp_simpson_rule(400, 0.0, 2.0, &integ_fun1));
    // println!("{}",com_trap_rule(5000,0.0,2.0,&integ_fun1));
    // println!("{}",com_midp_rul(10000,0.0,2.0,&integ_fun1));

    // println!("{}",romberg(6, 0.0, 0.3, &integ_fun3));

    // println!("{}",Gaussian(0.0, 1.0, &integ_fun2, gaussiancof::two));
    // println!("{}",Gaussian(0.0, 1.0, &integ_fun2, gaussiancof::three));
    // println!("{}",Gaussian(0.0, 1.0, &integ_fun2, gaussiancof::four));
    // println!("{}",Gaussian(0.0, 1.0, &integ_fun2, gaussiancof::five));

    let gdi=Gaussian_Double(gaussiancof::five, gaussiancof::five, 
        &integ_fn_ld, &integ_fn_lc, 0.5, 0.0, &integ_fun_l);
        println!("{}",gdi);
    // let xx:[f64;5]= [1.8,1.9,2.0,2.1,2.2];
    // let x1:[f64;5]=[10.889365,12.703199,14.778112,17.148957,19.855030];
    // let z1=three_point_dec(xx[2..5].to_vec(),x1[2..5].to_vec(),Formulas::First);
    // let z2=three_point_dec(xx[1..4].to_vec(),x1[1..4].to_vec(), Formulas::Middle);
    // println!("{}",z1);
    // println!("{}",z2);
    // println!("{}",five_point_dec(xx.to_vec(), x1.to_vec(), Formulas::Middle));
    // println!("{}",comp_simpson_rule(4, 0.0, 4.0, &fun1));
    // println!("{}",comp_simpson_rule(18, 0.0, PI, &fun2));
    // println!("{}",com_trap_rule(18, 0.0, PI, &fun2));
    // println!("{}",com_midp_rul(100, 0.0, PI, &fun2));
    // println!("{}",romberg(4, 0.0, 4.0, &fun1));
    // println!("{}",Gaussian(1.0, 3.0, &guass_fun1, gaussiancof::two));
    // println!("{}",Gaussian(1.0, 3.0, &guass_fun1, gaussiancof::three));

    // let asd=Gaussian_Double(gaussiancof::three,gaussiancof::three,
    //     &testd,&testc, 2.0,1.4, &fun4);
    // println!("{}",asd);
}

fn integ_fun_l(x:f64,y:f64)->f64{
    (y-x).exp()
}
fn integ_fn_ld(x:f64)->f64{
    0.5
}
fn integ_fn_lc(x:f64)->f64{
    0.0
}

fn integ_fun1(x:f64)->f64{
    let z=(2.0*x).exp();
    z*((3.0*x).sin())
}

fn integ_fun2(x:f64)->f64{
    let z=(-1.0*x).exp();
    z*x*x
}

fn integ_fun3(x:f64)->f64{
    if (0.0<=x)&&(x<=0.1){x*x*x+1.0}
    else if (0.1<x)&&(x<=0.2) { 1.001+0.03*(x-0.1)+0.3*(x-0.1)*(x-0.1)+2.0*(x-0.1)*(x-0.1)*(x-0.1)}
    else {
        1.009+0.15*(x-0.2)+0.9*(x-0.2)*(x-0.2)+2.0*(x-0.2)*(x-0.2)*(x-0.2)
    }
}

fn testd(x:f64)->f64{
    1.5
}

fn testc(x:f64)->f64{
    1.0
}

fn fun1(x:f64)->f64{
    x.exp()
}

fn fun2(x:f64)->f64{
    x.sin()
}

fn fun3(x:f64)->f64{
    x.exp()*x.cos()
}

fn guass_fun1(x:f64)->f64{
    let mut z=1.0;
    for i in 0..6{
        z=z*x
    }
    z=z-x*x*((2.0*x).sin());
    z
}

fn fun4(x:f64,y:f64)->f64{
    (x+2.0*y).ln()
}
