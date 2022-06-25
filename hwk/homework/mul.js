const { sqrt, abs, pow, add, multiply, subtract, divide, arg, sign, clone, complex, subset} = require("mathjs");

class muller_mtd{
    constructor(fun1,N,t1){
        this.fun=fun1
        this.max_step=N
        this.TOL=t1
    }

    show(p0=complex(0,0),p1=complex(0,0),p2=complex(0,0)){
        var p_0=p0,
            p_1=p1,
            p_2=p2,
            h_1=subtract(p1,p0),
            h_2=subtract(p2,p1),
            es1=(this.fun(p1)-this.fun(p0))/h_1,
            es2=(this.fun(p2)-this.fun(p1))/h_2,
            d=divide(subtract(es2,es1),add(h_2,h_1)),
            p_output=complex(0,0),
            i=3;

        while(i<=this.max_step){
            var b=add(es2,multiply(h_2,d))
            var D=sqrt(subtract(multiply(b,b),multiply(multiply(4,this.fun(p2)),d)))
            var E 

            if(abs(subtract(b,D))<abs(add(b,D))){
                E=add(b,D)
            }
            else{
                E=subtract(b,D)
            }

            var h=divide(multiply(-2,this.fun(p_2)),E)
            var p=add(p_2,h)

            if(abs(h)<this.TOL){
                p_output=p
                break
            }

            p_0=clone(p_1)
            p_1=clone(p_2)
            p_2=clone(p)
            h_1=subtract(p_1,p_0)
            h_2=subtract(p_2,p_1)
            es1=divide( subtract(this.fun(p_1),this.fun(p_0)) ,h_1)
            es2=divide( subtract(this.fun(p_2),this.fun(p_1)) ,h_2)
            d=divide(subtract(es2,es1),add(h_2,h_1))
            i++

            if(i==this.max_step){
                p_output=clone(p)
            }
            console.log(p)
        }
        return p_output
    }
}

function fun_1(x){
    return add(add(subtract(pow(x,4),multiply(3,pow(x,3))),pow(x,2)),add(x,1))
}
var m1=new muller_mtd(fun_1,100,pow(10,-10))
console.log(m1.show(complex(0.5,0),complex(-0.5,0),complex(0,0)))
