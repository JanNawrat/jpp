package Ada_Library is
    pragma Preelaborate;
    function factorial_loop(n: Integer) return Integer;

    function factorial_recursive(n: Integer) return Integer;

    function gcd_loop(
        a_in: Integer;
        b_in: Integer) return Integer;

    function gcd_recursive(
        a: Integer;
        b: Integer) return Integer;

    type DiophanticResult is record
        r : Integer;
        x : Integer := 0;
        y : Integer := 0;
    end record;

    function diophantic_loop(
        a : Integer;
        b : Integer;
        c : Integer) return DiophanticResult;

    function diophantic_recursive(
        r0_in : Integer;
        r1_in : Integer;
        c : Integer;
        s0_in : Integer := 1;
        s1_in : Integer := 0;
        t0_in : Integer := 0;
        t1_in : Integer := 1) return DiophanticResult;

private
end Ada_Library;
