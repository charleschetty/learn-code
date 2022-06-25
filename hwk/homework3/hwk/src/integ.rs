fn trapezoidal(a: f64, b: f64, f: &dyn Fn(f64) -> f64) -> f64 {
    let h = b - a;
    let tr = (f(a) + f(b)) * h / 2.0;
    tr
}

fn simpson(a: f64, b: f64, f: &dyn Fn(f64) -> f64) -> f64 {
    let h = (b - a) / 2.0;
    let si = (f(a) + 4.0 * f(a + h) + f(b)) * h / 3.0;
    si
}

pub fn comp_simpson_rule(n: u16, a: f64, b: f64, f: &dyn Fn(f64) -> f64) -> f64 {
    let XI0 = f(a) + f(b);
    let h = (b - a) / (n as f64);
    let mut XI1 = 0.0;
    let mut XI2 = 0.0;

    for i in 1..n {
        let X = &a + (i as f64) * &h;
        if (i % 2) == 0 {
            XI2 = XI2 + f(X);
        } else {
            XI1 = XI1 + f(X);
        }
    }
    let res = (XI0 + 2.0 * XI2 + 4.0 * XI1) * h / 3.0;
    res
}

pub fn com_trap_rule(n: u16, a: f64, b: f64, f: &dyn Fn(f64) -> f64) -> f64 {
    let h = (b - a) / (n as f64);
    let mut X = 0.0;
    for i in 1..n {
        let x = &a + (i as f64) * h;
        X = X + f(x);
    }
    let res = (f(a) + 2.0 * X + f(b)) * h / 2.0;
    res
}

pub fn com_midp_rul(n: u16, a: f64, b: f64, f: &dyn Fn(f64) -> f64) -> f64 {
    let mut X = 0.0;
    let h = (b - a) / ((n + 2) as f64);
    for i in 0..n / 2 + 1 {
        X = X + f(a + h * (2.0 * (i as f64) + 1.0));
        // println!("{},{},{}",i,(2.0*(i as f64)+1.0),a+h*(2.0*(i as f64)+1.0));
    }
    X * h * 2.0
}

pub fn romberg(n: u16, a: f64, b: f64, f: &dyn Fn(f64) -> f64) -> f64 {
    let mut h = (b - a);
    let mut R = Vec::new();
    R.push(Vec::new());
    R.push(Vec::new());
    R.push(Vec::new());
    for i in 0..n + 2 {
        R[1].push(a);
        R[2].push(a);
    }

    R[1][1] = (f(a) + f(b)) * h / 2.0;
    println!("R1_1: {}", R[1][1]);

    for i in 2..n + 1 {
        let mut tmpr21 = 0.0;
        for k in 1..(2 as i32).pow((i - 2) as u32) + 1 {
            tmpr21 = tmpr21 + f(a + (k as f64 - 0.5) * h);
        }
        let R21 = (R[1][1] + tmpr21 * h) / 2.0;
        R[2][1] = R21;

        for j in 2..i + 1 {
            let R2j = R[2][(j - 1) as usize]
                + (R[2][(j - 1) as usize] - R[1][(j - 1) as usize])
                    / ((4 as i32).pow(j as u32 - 1) - 1) as f64;
            R[2][j as usize] = R2j;
        }
        for j in 1..i + 1 {
            println!("R2_{}: {}", j, R[2][j as usize]);
        }

        h = h / 2.0;
        for j in 1..i + 1 {
            R[1][j as usize] = R[2][j as usize];
        }
    }
    R[2][n as usize]
}

pub enum gaussiancof {
    two,
    three,
    four,
    five,
}

pub fn Gaussian(a: f64, b: f64, f: &dyn Fn(f64) -> f64, z: gaussiancof) -> f64 {
    let mut root = Vec::new();
    let mut coff = Vec::new();
    let mut res = 0.0;
    match z {
        gaussiancof::two => {
            root = Vec::from([0.5773502692, -0.5773502692]);
            coff = Vec::from([1.0000000000, 1.0000000000]);
        }
        gaussiancof::three => {
            root = Vec::from([0.7745966692, 0.0000000000, -0.7745966692]);
            coff = Vec::from([0.5555555556, 0.8888888889, 0.5555555556]);
        }
        gaussiancof::four => {
            root = Vec::from([0.8611363116, 0.6521451549, -0.3399810436, -0.8611363116]);
            coff = Vec::from([0.3478548451, 0.6521451549, 0.6521451549, 0.3478548451]);
        }
        gaussiancof::five => {
            root = Vec::from([
                0.9061798459,
                0.5384693101,
                0.0000000000,
                -0.5384693101,
                -0.9061798459,
            ]);
            coff = Vec::from([
                0.2369268850,
                0.4786286705,
                0.5688888889,
                0.4786286705,
                0.2369268850,
            ]);
        }
    }
    for i in 0..root.len() {
        res = res + coff[i] * (f(((b - a) * root[i] + b + a) / 2.0) * (b - a) / 2.0);
    }
    res
}

pub fn Gaussian_Double(
    m: gaussiancof,
    n: gaussiancof,
    d: &dyn Fn(f64) -> f64,
    c: &dyn Fn(f64) -> f64,
    b: f64,
    a: f64,
    f: &dyn Fn(f64, f64) -> f64,
) -> f64 {
    let mut rootM = Vec::new();
    let mut coffM = Vec::new();
    let mut m1 = 0;
    let mut n1 = 0;
    match m {
        gaussiancof::two => {
            rootM = Vec::from([0.5773502692, -0.5773502692]);
            coffM = Vec::from([1.0000000000, 1.0000000000]);
            m1 = 2;
        }
        gaussiancof::three => {
            rootM = Vec::from([0.7745966692, 0.0000000000, -0.7745966692]);
            coffM = Vec::from([0.5555555556, 0.8888888889, 0.5555555556]);
            m1 = 3;
        }
        gaussiancof::four => {
            rootM = Vec::from([0.8611363116, 0.6521451549, -0.3399810436, -0.8611363116]);
            coffM = Vec::from([0.3478548451, 0.6521451549, 0.6521451549, 0.3478548451]);
            m1 = 4;
        }
        gaussiancof::five => {
            rootM = Vec::from([
                0.9061798459,
                0.5384693101,
                0.0000000000,
                -0.5384693101,
                -0.9061798459,
            ]);
            coffM = Vec::from([
                0.2369268850,
                0.4786286705,
                0.5688888889,
                0.4786286705,
                0.2369268850,
            ]);
            m1 = 5;
        }
    }

    let mut rootN = Vec::new();
    let mut coffN = Vec::new();
    match n {
        gaussiancof::two => {
            rootN = Vec::from([0.5773502692, -0.5773502692]);
            coffN = Vec::from([1.0000000000, 1.0000000000]);
            n1 = 2;
        }
        gaussiancof::three => {
            rootN = Vec::from([0.7745966692, 0.0000000000, -0.7745966692]);
            coffN = Vec::from([0.5555555556, 0.8888888889, 0.5555555556]);
            n1 = 3;
        }
        gaussiancof::four => {
            rootN = Vec::from([0.8611363116, 0.6521451549, -0.3399810436, -0.8611363116]);
            coffN = Vec::from([0.3478548451, 0.6521451549, 0.6521451549, 0.3478548451]);
            n1 = 4;
        }
        gaussiancof::five => {
            rootN = Vec::from([
                0.9061798459,
                0.5384693101,
                0.0000000000,
                -0.5384693101,
                -0.9061798459,
            ]);
            coffN = Vec::from([
                0.2369268850,
                0.4786286705,
                0.5688888889,
                0.4786286705,
                0.2369268850,
            ]);
            n1 = 5;
        }
    }

    let h1 = (b - a) / 2.0;
    let h2 = (b + a) / 2.0;
    let mut J = 0.0;

    for i in 0..m1 as usize {
        let mut JX = 0.0;
        let x = h1 * rootM[i] + h2;
        let d1 = d(x);
        let c1 = c(x);
        let k1 = (d1 - c1) / 2.0;
        let k2 = (d1 + c1) / 2.0;

        for j in 0..n1 as usize {
            let y = k1 * rootN[j] + k2;
            let Q = f(x, y);
            JX = JX + coffN[j] * Q;
        }
        J = J + coffM[i] * k1 * JX;
    }

    h1 * J
}
