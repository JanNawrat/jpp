pub fn factorial_loop(mut n: u64) -> u64 {
    let mut factorial = 1;
    while n > 1 {
        factorial *= n;
        n -= 1;
    }
    return factorial;
}

pub fn factorial_recursive(n: u64) -> u64 {
    if n <= 1 {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

pub fn gcd_loop(mut a: u64, mut b: u64) -> u64 {
    while a!= 0 && b != 0 {
        if a > b {
            a %= b;
        } else {
            b %= a;
        }
    }
    return if a == 0 {b} else {a};
}

pub fn gcd_recursive(a: u64, b: u64) -> u64 {
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

pub fn diophantic_loop(mut r0: i64, mut r1: i64, c: i64) -> (u8, i64, i64) {
    if r0 == 0 && r1 == 0 {
        return (if c == 0 {2} else {1}, 0, 0);
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
        return (1, 0, 0);
    }

    return (0, s0*c/r0, t0*c/r0);
}

pub fn diophantic_recursive(r0: i64, r1: i64, c :i64) -> (u8, i64, i64) {
    return diophantic_recursive_body(r0, r1, c, 1, 0, 0, 1);
}

fn diophantic_recursive_body(mut r0: i64, mut r1:i64, c:i64, mut s0: i64, mut s1: i64, mut t0: i64, mut t1:i64) -> (u8, i64, i64) {
    if r1 == 0 {
        if r0 == 0 {
            return (if c == 0 {2} else {1}, 0, 0);
        }
        if c % r0 != 0 {
            return (1, 0, 0);
        }
        let res1 = s0*c/r0;
        let res2 = t0*c/r0;
        println!("{res1}, {res2}");
        return (0, s0*c/r0, t0*c/r0);
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_factorial_loop() {
        assert_eq!(factorial_loop(0), 1);
        assert_eq!(factorial_loop(1), 1);
        assert_eq!(factorial_loop(2), 2);
        assert_eq!(factorial_loop(3), 6);
        assert_eq!(factorial_loop(4), 24);
        assert_eq!(factorial_loop(5), 120);
    }

    #[test]
    fn test_factorial_recursive() {
        assert_eq!(factorial_recursive(0), 1);
        assert_eq!(factorial_recursive(1), 1);
        assert_eq!(factorial_recursive(2), 2);
        assert_eq!(factorial_recursive(3), 6);
        assert_eq!(factorial_recursive(4), 24);
        assert_eq!(factorial_recursive(5), 120);
    }

    #[test]
    fn test_gcd_loop() {
        assert_eq!(gcd_loop(0, 0), 0);
        assert_eq!(gcd_loop(1, 0), 1);
        assert_eq!(gcd_loop(0, 1), 1);
        assert_eq!(gcd_loop(1, 1), 1);
        assert_eq!(gcd_loop(3, 15), 3);
        assert_eq!(gcd_loop(15, 3), 3);
        assert_eq!(gcd_loop(3, 17), 1);
        assert_eq!(gcd_loop(17, 3), 1);
        assert_eq!(gcd_loop(15, 625), 5);
        assert_eq!(gcd_loop(625, 15), 5);
    }

    #[test]
    fn test_gcd_recursive() {
        assert_eq!(gcd_recursive(0, 0), 0);
        assert_eq!(gcd_recursive(1, 0), 1);
        assert_eq!(gcd_recursive(0, 1), 1);
        assert_eq!(gcd_recursive(1, 1), 1);
        assert_eq!(gcd_recursive(3, 15), 3);
        assert_eq!(gcd_recursive(15, 3), 3);
        assert_eq!(gcd_recursive(3, 17), 1);
        assert_eq!(gcd_recursive(17, 3), 1);
        assert_eq!(gcd_recursive(15, 625), 5);
        assert_eq!(gcd_recursive(625, 15), 5);
    }

    #[test]
    fn test_diophantic_loop() {
        let mut res;
        let mut val1;
        let mut val2;
        // normal case
        (res ,val1, val2) = diophantic_loop(240, 46, 28);
        assert_eq!(res, 0);
        assert_eq!(240 * val1 + 46 * val2, 28);
        
        (res ,val1, val2) = diophantic_loop(-240, 46, 28);
        assert_eq!(res, 0);
        assert_eq!(-240 * val1 + 46 * val2, 28);
    
        (res ,val1, val2) = diophantic_loop(240, 46, -28);
        assert_eq!(res, 0);
        assert_eq!(240 * val1 + 46 * val2, -28);
    
        // c == 0, both values should be 0
        (res ,val1, val2) = diophantic_loop(240, 46, 0);
        assert_eq!(res, 0);
        assert_eq!(val1, 0);
        assert_eq!(val2, 0);
    
        // c isn't divisible by GCD, no results
        (res, _, _) = diophantic_loop(240, 46, 3);
        assert_eq!(res, 1);
    
        // a = b = 0, c != 0, no results
        (res, _, _) = diophantic_loop(0, 0, 1);
        assert_eq!(res, 1);
    
        // a = b = c = 0, infinite results
        (res, _, _) = diophantic_loop(0, 0, 0);
        assert_eq!(res, 2); 
    }

    #[test]
    fn test_diophantic_recursive() {
        let mut res;
        let mut val1;
        let mut val2;
        // normal case
        (res ,val1, val2) = diophantic_recursive(240, 46, 28);
        assert_eq!(res, 0);
        assert_eq!(240 * val1 + 46 * val2, 28);
        
        (res ,val1, val2) = diophantic_recursive(-240, 46, 28);
        assert_eq!(res, 0);
        assert_eq!(-240 * val1 + 46 * val2, 28);
    
        (res ,val1, val2) = diophantic_recursive(240, 46, -28);
        assert_eq!(res, 0);
        assert_eq!(240 * val1 + 46 * val2, -28);
    
        // c == 0, both values should be 0
        (res ,val1, val2) = diophantic_recursive(240, 46, 0);
        assert_eq!(res, 0);
        assert_eq!(val1, 0);
        assert_eq!(val2, 0);
    
        // c isn't divisible by GCD, no results
        (res, _, _) = diophantic_recursive(240, 46, 3);
        assert_eq!(res, 1);
    
        // a = b = 0, c != 0, no results
        (res, _, _) = diophantic_recursive(0, 0, 1);
        assert_eq!(res, 1);
    
        // a = b = c = 0, infinite results
        (res, _, _) = diophantic_recursive(0, 0, 0);
        assert_eq!(res, 2); 
    }
}
