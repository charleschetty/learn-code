class bisection{
    constructor(fun1,left_val,right_val,N,bais1){
        this.fun=fun1;
        this.a=left_val
        this.b=right_val
        this.max_step=N
        this.bais=bais1
    }
    check(){
        var check_val;
        if(this.fun(this.a)*this.fun(this.b)<0){
            check_val=true
        }
        else{check_val=false}
        return check_val
    }

    show(){
        var temp_step=0,
            a_temp=this.a,
            b_temp=this.b,
            output_p=0,
            output_bais=[],
            output_p_temp=[];

        while(temp_step<=this.max_step){
            var p=a_temp+(b_temp-a_temp)/2
            var temp_val=this.fun(p)
            output_bais.push(p)
            output_p_temp.push(temp_val)
            if(temp_val==0||(b_temp-a_temp)<this.bais){
                output_p=p
                break
            }
            else{
                temp_step++
                if(temp_val*this.fun(a_temp)>0){a_temp=p}
                else{b_temp=p}
            }
            if(temp_step==this.max_step){output_p=p}
        }
        this.temp_step=output_p_temp
        this.bais_step=output_bais
        return output_p
    }
}

// function the_fun1(x){
    // return x*x-10*x+3
// }

// var b1=new bisection(the_fun1,1,15,20,0.0001)
// var p1=b1.show()
// console.log(p1)
// console.log(b1.temp_step)
// console.log(b1.bais_step)



class fixed_point{
    constructor(the_fun,N,bias1){
        this.fun=the_fun
        this.max_step=N
        this.bias=bias1
    }
    show(p){
        var output_p=0,
            temp_p=p,
            temp_step=0,
            temp_p_list=[];
        while(temp_step<=this.max_step){
            var temp_p_step=this.fun(temp_p)
            temp_p_list.push(temp_p_step)
            if(Math.abs(temp_p_step-temp_p)<this.bias){
                output_p=temp_p_step
                break
            }
            else{
                temp_step++
                temp_p=temp_p_step
            }
            if(temp_step==this.max_step){output_p=temp_p_step}
        }    
        this.p_list=temp_p_list
        return output_p 
    }
}

// function the_fun2(x){
//     return Math.sqrt(10-Math.pow(x,3))/2
// }

// var f1=new fixed_point(the_fun2,30,0.001)
// console.log(f1.show(1.5))
// console.log(f1.p_list)

class Newton_mtd{
    constructor(the_fun,thefun_grad,N,bias1){
        this.fun=the_fun
        this.max_step=N
        this.bias=bias1
        this.fun_grad=thefun_grad
    }

    show(p){
        var temp_step=0,
            temp_p=p,
            temp_p_list=[],
            output_p=0;

        while(temp_step<this.max_step){
            var temp_p_step=temp_p-this.fun(temp_p)/this.fun_grad(temp_p)
            if(Math.abs(temp_p-temp_p_step)<this.bias){
                output_p=temp_p_step
                break
            }
            temp_step++
            temp_p=temp_p_step
            temp_p_list.push(temp_p)

            if(temp_step==this.max_step){output_p=temp_p}
        }
        this.p_list=temp_p_list
        return output_p
    }
}

function the_fun3(x){
    return Math.cos(x)-x
}

function the_fun3_grad(x){
    return Math.sin(x)*(-1)-1
}

// var ne1=new Newton_mtd(the_fun3,the_fun3_grad,20,Math.pow(10,-10))
// // console.log(ne1.show(Math.PI/4))
// console.log(ne1.p_list)

class secant_mtd extends Newton_mtd{
    show(p0,p1){
        var temp_step=0,
            temp_p0=p0,
            temp_p1=p1,
            temp_q0=this.fun(temp_p0),
            temp_q1=this.fun(temp_p1), 
            temp_p_list=[],
            output_p=0;
        
        while(temp_step<=this.max_step){
            var temp_p_step=temp_p1-temp_q1*(temp_p1-temp_p0)/(temp_q1-temp_q0)
            if(Math.abs(temp_p_step-temp_p1)<this.bias){
                output_p=temp_p_step
                break
            }
            temp_step++

            temp_p0=temp_p1
            temp_q0=temp_q1
            temp_p1=temp_p_step
            temp_q1=this.fun(temp_p_step)
            temp_p_list.push(temp_p_step)
            if(temp_step==this.max_step){output_p=temp_p_step}
        }
        this.p_list=temp_p_list
        return output_p
    }
}

// var sec1=new secant_mtd(the_fun3,the_fun3_grad,20,Math.pow(10,-10))
// console.log(sec1.show(0.5,Math.PI/4))
// console.log(sec1.p_list)

class false_posti extends Newton_mtd{
    show(p0,p1){
        var temp_step=0,
            temp_p0=p0,
            temp_p1=p1,
            temp_q0=this.fun(temp_p0),
            temp_q1=this.fun(temp_p1), 
            temp_p_list=[],
            output_p=0;

        while(temp_step<=this.max_step){
            var temp_p_step=temp_p1-temp_q1*(temp_p1-temp_p0)/(temp_q1-temp_q0)
            if(Math.abs(temp_p_step-temp_p1)<this.bias){
                output_p=temp_p_step
                break
            }
            temp_step++
            var tem_q_step=this.fun(temp_p_step)
            if(tem_q_step*temp_q1<0){
                temp_p0=temp_p1
                temp_q0=temp_q1
            }
            temp_p1=temp_p_step
            temp_q1=tem_q_step
            temp_p_list.push(temp_p_step)
            if(temp_step==this.max_step){output_p=temp_p_step}
        }
        this.p_list=temp_p_list
        return output_p 
    }
}


// var fal1=new false_posti(the_fun3,the_fun3_grad,20,Math.pow(10,-10))
// console.log(fal1.show(0.5,Math.PI/4))
// console.log(fal1.p_list)
class steffensen_mtd{
    constructor(the_fun,N,eps){
        this.fun=the_fun
        this.max_step=N
        this.bias=eps
    }

    show(p){
        var p_temp=p,
            temp_step=0,
            output_p=0,
            output_p_list=[];

        while(temp_step<=this.max_step){
            var temp_p1=this.fun(p_temp),
                temp_p2=this.fun(temp_p1),
                temp_p_step=p_temp-Math.pow(temp_p1-p_temp,2)/(temp_p2-2*temp_p1+p_temp);
            if(Math.abs(p_temp-temp_p_step)<this.bias){
                output_p=temp_p_step
                break
            }      
            temp_step++
            p_temp=temp_p_step 
            output_p_list.push(p_temp)
            if(temp_step==this.max_step){
                output_p=p_temp
                break
            }
        }
        this.p_list=output_p_list
        return output_p
    }
}

function the_fun3_fix(x){
    return Math.cos(x)
}

// var st1=new steffensen_mtd(the_fun3_fix,100,Math.pow(10,-10))
// console.log(st1.show(0.5))
// console.log(st1.p_list)

class horner_mtd{
    constructor(pln1=[]){  //2x^2+3x+4:[2,3,4]
        this.pln=pln1
        this.len=pln1.length
        // this.x_0=x
    }

    show(x){
        var x_0=x
        var y_output=this.pln[0]
        var z_output=this.pln[0]

        for(var i=1;i<this.len-1;i++){
            y_output=x_0*y_output+this.pln[i]
            z_output=x_0*z_output+y_output
        }

        y_output=x_0*y_output+this.pln[this.len-1]

        var output=[]
        output.push(y_output)
        output.push(z_output)
        return output
    }

}

// var ho1=new horner_mtd([3,2,1,1])
// console.log(ho1.show(1))

function time_avg(){
    var b1=new bisection(the_fun3,0,1,100,Math.pow(10,-10))  
    var f1=new fixed_point(the_fun3_fix,100,Math.pow(10,-10))
    var n1=new Newton_mtd(the_fun3,the_fun3_grad,100,Math.pow(10,-10))
    var s1=new secant_mtd(the_fun3,the_fun3_grad,100,Math.pow(10,-10))
    var fal1=new false_posti(the_fun3,the_fun3_grad,20,Math.pow(10,-10))
    var st1=new steffensen_mtd(the_fun3_fix,100,Math.pow(10,-10))

    var d11=new Date()
    for(var i=0;i<Math.pow(10,5);i++){
        var temp=b1.show()
    }
    var d12=new Date()
    console.log(d12-d11)

    var d21=new Date()
    for(var i=0;i<Math.pow(10,5);i++){
        var temp=f1.show(0.5)
    }
    var d22=new Date()
    console.log(d22-d21)

    var d31=new Date()
    for(var i=0;i<Math.pow(10,5);i++){
        var temp=n1.show(0.5)
    }
    var d32=new Date()
    console.log(d32-d31)

    var d41=new Date()
    for(var i=0;i<Math.pow(10,5);i++){
        var temp=s1.show(0,1)
    }
    var d42=new Date()
    console.log(d42-d41)

    var d51=new Date()
    for(var i=0;i<Math.pow(10,5);i++){
        var temp=fal1.show(0,1)
    }
    var d52=new Date()
    console.log(d52-d51)
    // return temp
    
    var d61=new Date()
    for(var i=0;i<Math.pow(10,5);i++){
        var temp=st1.show(0.5)
    }
    var d62=new Date()
    console.log(d62-d61)
}


// var b1=new bisection(the_fun3,0,1,100,Math.pow(10,-10))
// console.log(b1.show())
// console.log(b1.temp_step.length)

// var f1=new fixed_point(the_fun3_fix,100,Math.pow(10,-10))
// console.log(f1.show(0.5))
// console.log(f1.p_list.length)

// var n1=new Newton_mtd(the_fun3,the_fun3_grad,100,Math.pow(10,-10))
// console.log(n1.show(0.5))
// console.log(n1.p_list.length)

// var s1=new secant_mtd(the_fun3,the_fun3_grad,100,Math.pow(10,-10))
// console.log(s1.show(0,1))
// console.log(s1.p_list.length)

// var fal1=new false_posti(the_fun3,the_fun3_grad,20,Math.pow(10,-10))
// console.log(fal1.show(0,1))
// console.log(fal1.p_list.length)

// var st1=new steffensen_mtd(the_fun3_fix,100,Math.pow(10,-10))
// console.log(st1.show(0.5))
// console.log(st1.p_list.length)
time_avg()
