#[repr(C)]
pub struct DiophanticResult {
    pub r: cty::c_int,
    pub x: cty::c_int,
    pub y: cty::c_int,
}

#[link(name="c_library", kind="static")]
extern "C" {
    pub fn factorial_loop(
        n: cty::c_int,
    ) -> cty::c_int;

    pub fn factorial_recursive(
        n: cty::c_int,
    ) -> cty::c_int;

    pub fn gcd_loop(
        a: cty::c_int,
        b: cty::c_int,
    ) -> cty::c_int;

    pub fn gcd_recursive(
        a: cty::c_int,
        b: cty::c_int,
    ) -> cty::c_int;

    pub fn diophantic_loop(
        r0: cty::c_int,
        r1: cty::c_int,
        c:  cty::c_int,
    ) -> DiophanticResult;

    pub fn diophantic_recursive_body(
        r0: cty::c_int,
        r1: cty::c_int,
        c:  cty::c_int,
        s0: cty::c_int,
        s1: cty::c_int,
        t0: cty::c_int,
        t1: cty::c_int,
    ) -> DiophanticResult;

    pub fn diophantic_recursive(
        a: cty::c_int,
        b: cty::c_int,
        c: cty::c_int,
    ) -> DiophanticResult;
}

pub fn factorial_loop_wrapper(
    n: cty::c_int,
) -> cty::c_int {
    return unsafe {factorial_loop(n)};
}

pub fn factorial_recursive_wrapper(
    n: cty::c_int,
) -> cty::c_int {
    return unsafe {factorial_recursive(n)};
}

pub fn gcd_loop_wrapper(
    a: cty::c_int,
    b: cty::c_int,
) -> cty::c_int {
    return unsafe {gcd_loop(a, b)};
}

pub fn gcd_recursive_wrapper(
    a: cty::c_int,
    b: cty::c_int,
) -> cty::c_int {
    return unsafe {gcd_recursive(a, b)};
}

pub fn diophantic_loop_wrapper(
    r0: cty::c_int,
    r1: cty::c_int,
    c:  cty::c_int,
) -> (cty::c_int, cty::c_int, cty::c_int) {
    let res = unsafe {diophantic_loop(r0, r1, c)};
    return (res.r, res.x, res. y);
}

pub fn diophantic_recursive_wrapper(
    r0: cty::c_int,
    r1: cty::c_int,
    c:  cty::c_int,
) -> (cty::c_int, cty::c_int, cty::c_int) {
    let res = unsafe {diophantic_recursive(r0, r1, c)};
    return (res.r, res.x, res. y);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_factorial_loop() {
        assert_eq!(factorial_loop_wrapper(0), 1);
        assert_eq!(factorial_loop_wrapper(1), 1);
        assert_eq!(factorial_loop_wrapper(2), 2);
        assert_eq!(factorial_loop_wrapper(3), 6);
        assert_eq!(factorial_loop_wrapper(4), 24);
        assert_eq!(factorial_loop_wrapper(5), 120);
    }

    #[test]
    fn test_factorial_recursive() {
        assert_eq!(factorial_recursive_wrapper(0), 1);
        assert_eq!(factorial_recursive_wrapper(1), 1);
        assert_eq!(factorial_recursive_wrapper(2), 2);
        assert_eq!(factorial_recursive_wrapper(3), 6);
        assert_eq!(factorial_recursive_wrapper(4), 24);
        assert_eq!(factorial_recursive_wrapper(5), 120);
    }

    #[test]
    fn test_gcd_loop() {
        assert_eq!(gcd_loop_wrapper(0, 0), 0);
        assert_eq!(gcd_loop_wrapper(1, 0), 1);
        assert_eq!(gcd_loop_wrapper(0, 1), 1);
        assert_eq!(gcd_loop_wrapper(1, 1), 1);
        assert_eq!(gcd_loop_wrapper(3, 15), 3);
        assert_eq!(gcd_loop_wrapper(15, 3), 3);
        assert_eq!(gcd_loop_wrapper(3, 17), 1);
        assert_eq!(gcd_loop_wrapper(17, 3), 1);
        assert_eq!(gcd_loop_wrapper(15, 625), 5);
        assert_eq!(gcd_loop_wrapper(625, 15), 5);
    }

    #[test]
    fn test_gcd_recursive() {
        assert_eq!(gcd_recursive_wrapper(0, 0), 0);
        assert_eq!(gcd_recursive_wrapper(1, 0), 1);
        assert_eq!(gcd_recursive_wrapper(0, 1), 1);
        assert_eq!(gcd_recursive_wrapper(1, 1), 1);
        assert_eq!(gcd_recursive_wrapper(3, 15), 3);
        assert_eq!(gcd_recursive_wrapper(15, 3), 3);
        assert_eq!(gcd_recursive_wrapper(3, 17), 1);
        assert_eq!(gcd_recursive_wrapper(17, 3), 1);
        assert_eq!(gcd_recursive_wrapper(15, 625), 5);
        assert_eq!(gcd_recursive_wrapper(625, 15), 5);
    }

    #[test]
    fn test_diophantic_loop() {
        let mut res;
        let mut val1;
        let mut val2;
        // normal case
        (res ,val1, val2) = diophantic_loop_wrapper(240, 46, 28);
        assert_eq!(res, 0);
        assert_eq!(240 * val1 + 46 * val2, 28);
        
        (res ,val1, val2) = diophantic_loop_wrapper(-240, 46, 28);
        assert_eq!(res, 0);
        assert_eq!(-240 * val1 + 46 * val2, 28);
    
        (res ,val1, val2) = diophantic_loop_wrapper(240, 46, -28);
        assert_eq!(res, 0);
        assert_eq!(240 * val1 + 46 * val2, -28);
    
        // c == 0, both values should be 0
        (res ,val1, val2) = diophantic_loop_wrapper(240, 46, 0);
        assert_eq!(res, 0);
        assert_eq!(val1, 0);
        assert_eq!(val2, 0);
    
        // c isn't divisible by GCD, no results
        (res, _, _) = diophantic_loop_wrapper(240, 46, 3);
        assert_eq!(res, 1);
    
        // a = b = 0, c != 0, no results
        (res, _, _) = diophantic_loop_wrapper(0, 0, 1);
        assert_eq!(res, 1);
    
        // a = b = c = 0, infinite results
        (res, _, _) = diophantic_loop_wrapper(0, 0, 0);
        assert_eq!(res, 2); 
    }

    #[test]
    fn test_diophantic_recursive() {
        let mut res;
        let mut val1;
        let mut val2;
        // normal case
        (res ,val1, val2) = diophantic_recursive_wrapper(240, 46, 28);
        assert_eq!(res, 0);
        assert_eq!(240 * val1 + 46 * val2, 28);
        
        (res ,val1, val2) = diophantic_recursive_wrapper(-240, 46, 28);
        assert_eq!(res, 0);
        assert_eq!(-240 * val1 + 46 * val2, 28);
    
        (res ,val1, val2) = diophantic_recursive_wrapper(240, 46, -28);
        assert_eq!(res, 0);
        assert_eq!(240 * val1 + 46 * val2, -28);
    
        // c == 0, both values should be 0
        (res ,val1, val2) = diophantic_recursive_wrapper(240, 46, 0);
        assert_eq!(res, 0);
        assert_eq!(val1, 0);
        assert_eq!(val2, 0);
    
        // c isn't divisible by GCD, no results
        (res, _, _) = diophantic_recursive_wrapper(240, 46, 3);
        assert_eq!(res, 1);
    
        // a = b = 0, c != 0, no results
        (res, _, _) = diophantic_recursive_wrapper(0, 0, 1);
        assert_eq!(res, 1);
    
        // a = b = c = 0, infinite results
        (res, _, _) = diophantic_recursive_wrapper(0, 0, 0);
        assert_eq!(res, 2); 
    }
}
