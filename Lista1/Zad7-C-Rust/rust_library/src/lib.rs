#[repr(C)]
pub struct DiophanticResult {
    r: u8,
    x: i64,
    y: i64
}

#[no_mangle]
pub extern "C" fn factorial_loop(mut n: u64) -> u64 {
    let mut factorial = 1;
    while n > 1 {
        factorial *= n;
        n -= 1;
    }
    return factorial;
}


#[no_mangle]
pub extern "C" fn factorial_recursive(n: u64) -> u64 {
    if n <= 1 {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}


#[no_mangle]
pub extern "C" fn gcd_loop(mut a: u64, mut b: u64) -> u64 {
    while a!= 0 && b != 0 {
        if a > b {
            a %= b;
        } else {
            b %= a;
        }
    }
    return if a == 0 {b} else {a};
}


#[no_mangle]
pub extern "C" fn gcd_recursive(a: u64, b: u64) -> u64 {
    if a == 0 {
        return b;
    } else if b == 0 {
        return a;
    } else if a > b {
        return gcd_recursive(a % b, b);
    } else {
        return gcd_recursive(a, b % a);
    }
}

#[no_mangle]
pub extern "C" fn diophantic_loop(mut r0: i64, mut r1: i64, c: i64) -> DiophanticResult {
    if r0 == 0 && r1 == 0 {
        return DiophanticResult{
            r: if c == 0 {2} else {1},
            x: 0,
            y: 0
        };
    }

    let mut q;
    let mut tmp;
    let mut s0 = 1;
    let mut s1 = 0;
    let mut t0 = 0;
    let mut t1 = 1;

    while r1 != 0 {
        q = r0/r1;
        tmp = r1;
        r1 = r0 - r1*q;
        r0 = tmp;

        tmp = s1;
        s1 = s0 - s1*q;
        s0 = tmp;

        tmp = t1;
        t1 = t0 - t1*q;
        t0 = tmp; 
    }

    if c%r0 != 0 {
        return DiophanticResult{
            r: 1,
            x: 0,
            y: 0
        };
    }

    return DiophanticResult{
        r: 0,
        x: s0*c/r0,
        y: t0*c/r0
    };
}

#[no_mangle]
pub extern "C" fn diophantic_recursive(r0: i64, r1: i64, c :i64) -> DiophanticResult {
    return diophantic_recursive_body(r0, r1, c, 1, 0, 0, 1);
}

#[no_mangle]
pub extern "C" fn diophantic_recursive_body(mut r0: i64, mut r1:i64, c:i64, mut s0: i64, mut s1: i64, mut t0: i64, mut t1:i64) -> DiophanticResult {
    if r1 == 0 {
        if r0 == 0 {
            return DiophanticResult{
                r: if c == 0 {2} else {1},
                x: 0,
                y: 0
            };
        }
        if c % r0 != 0 {
            return DiophanticResult{
                r: 1,
                x: 0,
                y: 0
            };
        }
        let res1 = s0*c/r0;
        let res2 = t0*c/r0;
        println!("{res1}, {res2}");
        return DiophanticResult{
            r: 0,
            x: s0*c/r0,
            y: t0*c/r0
        };
    }

    let mut tmp;
    let q = r0/r1;

    tmp = r1;
    r1 = r0 - r1*q;
    r0 = tmp;

    tmp = s1;
    s1 = s0 - s1*q;
    s0 = tmp;

    tmp = t1;
    t1 = t0 - t1*q;
    t0 = tmp;

    return diophantic_recursive_body(r0, r1, c, s0, s1, t0, t1);
}

// #[cfg(test)]
// mod tests {
//     use super::*;

//     #[test]
//     fn it_works() {
//         let result = add(2, 2);
//         assert_eq!(result, 4);
//     }
// }
