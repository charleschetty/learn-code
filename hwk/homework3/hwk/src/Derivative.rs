pub enum Formulas{
    First,
    Middle,
    End,
}

pub fn three_point_dec(x:Vec<f64>,fx:Vec<f64>,z:Formulas)->f64
{
    let h=x[1]-x[0];
    match z {
        Formulas::First=>{
            let fdx=((-3.0)*fx[0]+4.0*fx[1]-fx[2])/(2.0*h);fdx
        }
        Formulas::Middle=>{
            let fdx=(-1.0*fx[0]+fx[2])/(2.0*h);fdx
        }
        Formulas::End=>{
            let fdx=(fx[0]-4.0*fx[1]+3.0*fx[2])/(2.0*h);fdx
        }
    }
}

pub fn five_point_dec(x:Vec<f64>,fx:Vec<f64>,z:Formulas)->f64{
    let h=x[1]-x[0];
    match z {
        Formulas::First=>{
            let fdx=(-25.0*fx[0]+48.0*fx[1]-36.0*fx[2]+16.0*fx[3]-3.0*fx[4])/(12.0*h);
            fdx
        }
        Formulas::Middle=>{
            let fdx=(fx[0]-8.0*fx[1]+8.0*fx[3]-fx[4])/(12.0*h);
            fdx
        }
        Formulas::End=>{
            let fdx=(3.0*fx[0]-16.0*fx[1]+36.0*fx[2]-48.0*fx[3]+25.0*fx[4])/(12.0*h);
            fdx
        }
    }
}