package body Test is

procedure test_factorial_loop
is
    function factorial_loop(n : int) return int
    with
      Import        => True,
      Convention    => C;

    pragma Assertion_Policy (Assert => Check);
begin
    pragma Assert ( factorial_loop(0) = 1, "Factorial loop failed");
    pragma Assert ( factorial_loop(1) = 1, "Factorial loop failed" );
    pragma Assert ( factorial_loop(2) = 2, "Factorial loop failed" );
    pragma Assert ( factorial_loop(3) = 6, "Factorial loop failed" );
    pragma Assert ( factorial_loop(4) = 24, "Factorial loop failed" );
    pragma Assert ( factorial_loop(5) = 120, "Factorial loop failed" );
end test_factorial_loop;

procedure test_factorial_recursive
is
    function factorial_recursive(n : int) return int
    with
      Import        => True,
      Convention    => C;

    pragma Assertion_Policy (Assert => Check);
begin
    pragma Assert ( factorial_recursive(0) = 1, "Factorial recursive failed");
    pragma Assert ( factorial_recursive(1) = 1, "Factorial recursive failed" );
    pragma Assert ( factorial_recursive(2) = 2, "Factorial recursive failed" );
    pragma Assert ( factorial_recursive(3) = 6, "Factorial recursive failed" );
    pragma Assert ( factorial_recursive(4) = 24, "Factorial recursive failed" );
    pragma Assert ( factorial_recursive(5) = 120, "Factorial recursive failed" );
end test_factorial_recursive;

procedure test_GCD_loop
is
    function gcd_loop(a: int; b: int) return int
    with
      Import        => True,
      Convention    => C;

    pragma Assertion_Policy (Assert => Check);
begin
    pragma Assert ( gcd_loop(0, 0) = 0, "GCD loop failed" );
    pragma Assert ( gcd_loop(1, 0) = 1, "GCD loop failed" );
    pragma Assert ( gcd_loop(0, 1) = 1, "GCD loop failed" );
    pragma Assert ( gcd_loop(1, 1) = 1, "GCD loop failed" );
    pragma Assert ( gcd_loop(3, 15) = 3, "GCD loop failed" );
    pragma Assert ( gcd_loop(15, 3) = 3, "GCD loop failed" );
    pragma Assert ( gcd_loop(3, 17) = 1, "GCD loop failed" );
    pragma Assert ( gcd_loop(17, 3) = 1, "GCD loop failed" );
    pragma Assert ( gcd_loop(15, 625) = 5, "GCD loop failed" );
    pragma Assert ( gcd_loop(625, 15) = 5, "GCD loop failed" );
end test_GCD_loop;

procedure test_GCD_recursive
is
    function gcd_recursive(a: int; b: int) return int
    with
      Import        => True,
      Convention    => C;
      
    pragma Assertion_Policy (Assert => Check);
begin
    pragma Assert ( gcd_recursive(0, 0) = 0, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(1, 0) = 1, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(0, 1) = 1, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(1, 1) = 1, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(3, 15) = 3, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(15, 3) = 3, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(3, 17) = 1, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(17, 3) = 1, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(15, 625) = 5, "GCD recursive failed" );
    pragma Assert ( gcd_recursive(625, 15) = 5, "GCD recursive failed" );
end test_GCD_recursive;

procedure test_diophantic_loop
is
    type DiophanticResult is record
        r : Interfaces.C.int;
        x : Interfaces.C.int;
        y : interfaces.C.int;
    end record;
    pragma Convention (C, DiophanticResult);

    function diophantic_loop(r0: int; r1: int; c: int) return DiophanticResult
    with
      Import        => True,
      Convention    => C;

    res : DiophanticResult;
    pragma Assertion_Policy (Assert => Check);
begin
    -- normal case
    res := diophantic_loop(240, 46, 28);
    pragma Assert ( res.r = 0, "Diophantic loop failed" );
    pragma Assert ( 240 * res.x + 46 * res.y = 28, "Diophantic loop failed" );
    
    res := diophantic_loop(-240, 46, 28);
    pragma Assert ( res.r = 0, "Diophantic loop failed" );
    pragma Assert ( -240 * res.x + 46 * res.y = 28, "Diophantic loop failed" );

    res := diophantic_loop(240, 46, -28);
    pragma Assert ( res.r = 0, "Diophantic loop failed" );
    pragma Assert ( 240 * res.x + 46 * res.y = -28, "Diophantic loop failed" );

    -- c, 0, both values should be 0
    res := diophantic_loop(240, 46, 0);
    pragma Assert ( res.r = 0, "Diophantic loop failed" );
    pragma Assert ( res.x = 0, "Diophantic loop failed" );
    pragma Assert ( res.y = 0, "Diophantic loop failed" );

    -- c isn't divisible by GCD, no results
    res := diophantic_loop(240, 46, 3);
    pragma Assert ( res.r = 1, "Diophantic loop failed" );

    -- a = b = 0, c != 0, no results
    res := diophantic_loop(0, 0, 1);
    pragma Assert ( res.r = 1, "Diophantic loop failed" );

    -- a = b = c = 0, infinite results
    res := diophantic_loop(0, 0, 0);
    pragma Assert ( res.r = 2, "Diophantic loop failed" ); 
end test_diophantic_loop;

procedure test_diophantic_recursive
is
    type DiophanticResult is record
        r : Interfaces.C.int;
        x : Interfaces.C.int;
        y : interfaces.C.int;
    end record;
    pragma Convention (C, DiophanticResult);

    function diophantic_recursive(a: int; b: int; c: int) return DiophanticResult
    with
      Import        => True,
      Convention    => C;

    res : DiophanticResult;
    pragma Assertion_Policy (Assert => Check);
begin
    -- normal case
    res := diophantic_recursive(240, 46, 28);
    pragma Assert ( res.r = 0, "Diophantic recursive failed" );
    pragma Assert ( 240 * res.x + 46 * res.y = 28, "Diophantic recursive failed" );
    
    res := diophantic_recursive(-240, 46, 28);
    pragma Assert ( res.r = 0, "Diophantic recursive failed" );
    pragma Assert ( -240 * res.x + 46 * res.y = 28, "Diophantic recursive failed" );

    res := diophantic_recursive(240, 46, -28);
    pragma Assert ( res.r = 0, "Diophantic recursive failed" );
    pragma Assert ( 240 * res.x + 46 * res.y = -28, "Diophantic recursive failed" );

    -- c, 0, both values should be 0
    res := diophantic_recursive(240, 46, 0);
    pragma Assert ( res.r = 0, "Diophantic recursive failed" );
    pragma Assert ( res.x = 0, "Diophantic recursive failed" );
    pragma Assert ( res.y = 0, "Diophantic recursive failed" );

    -- c isn't divisible by GCD, no results
    res := diophantic_recursive(240, 46, 3);
    pragma Assert ( res.r = 1, "Diophantic recursive failed" );

    -- a = b = 0, c != 0, no results
    res := diophantic_recursive(0, 0, 1);
    pragma Assert ( res.r = 1, "Diophantic recursive failed" );

    -- a = b = c = 0, infinite results
    res := diophantic_recursive(0, 0, 0);
    pragma Assert ( res.r = 2, "Diophantic recursive failed" ); 
end test_diophantic_recursive;

end Test;



--  void test_diophantic_loop(void) {
--      DiophanticResult res;
--      // normal case
--      res = diophantic_loop(240, 46, 28);
--      pragma Assert ( 0, res.r );
--      pragma Assert ( 28, 240 * res.x + 46 * res.y );
    
--      res = diophantic_loop(-240, 46, 28);
--      pragma Assert ( 0, res.r );
--      pragma Assert ( 28, -240 * res.x + 46 * res.y );

--      res = diophantic_loop(240, 46, -28);
--      pragma Assert ( 0, res.r );
--      pragma Assert ( -28, 240 * res.x + 46 * res.y );

--      // c, 0, both values should be 0
--      res = diophantic_loop(240, 46, 0);
--      pragma Assert ( 0, res.r );
--      pragma Assert ( 0, res.x );
--      pragma Assert ( 0, res.y );

--      // c isn't divisible by GCD, no results
--      res = diophantic_loop(240, 46, 3);
--      pragma Assert ( 1, res.r );

--      // a = b = 0, c != 0, no results
--      res = diophantic_loop(0, 0, 1);
--      pragma Assert ( 1, res.r );

--      // a = b = c = 0, infinite results
--      res = diophantic_loop(0, 0, 0);
--      pragma Assert ( 2, res.r ); 
--  }

--  void test_diophantic_recursive(void) {
--      DiophanticResult res;
--      // normal case
--      res = diophantic_recursive(240, 46, 28);
--      pragma Assert ( 0, res.r );
--      pragma Assert ( 28, 240 * res.x + 46 * res.y );
    
--      res = diophantic_recursive(-240, 46, 28);
--      pragma Assert ( 0, res.r );
--      pragma Assert ( 28, -240 * res.x + 46 * res.y );

--      res = diophantic_recursive(240, 46, -28);
--      pragma Assert ( 0, res.r );
--      pragma Assert ( -28, 240 * res.x + 46 * res.y );

--      // c, 0, both values should be 0
--      res = diophantic_recursive(240, 46, 0);
--      pragma Assert ( 0, res.r );
--      pragma Assert ( 0, res.x );
--      pragma Assert ( 0, res.y );

--      // c isn't divisible by GCD, no results
--      res = diophantic_recursive(240, 46, 3);
--      pragma Assert ( 1, res.r );

--      // a = b = 0, c != 0, no results
--      res = diophantic_recursive(0, 0, 1);
--      pragma Assert ( 1, res.r );

--      // a = b = c = 0, infinite results
--      res = diophantic_recursive(0, 0, 0);
--      pragma Assert ( 2, res.r ); 
--  }
