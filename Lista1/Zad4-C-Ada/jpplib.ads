with Interfaces.C; use Interfaces.C;

package JPPLib is
    pragma Preelaborate;
    function factorial_loop(n: Integer) return Integer
    with
        Export        => True,
        Convention    => C,
        External_Name => "factorial_loop";

    function factorial_recursive(n: Integer) return Integer
    with
        Export        => True,
        Convention    => C,
        External_Name => "factorial_recursive";

    function gcd_loop(
        a_in: Integer;
        b_in: Integer) return Integer
    with
        Export        => True,
        Convention    => C,
        External_Name => "gcd_loop";

    function gcd_recursive(
        a: Integer;
        b: Integer) return Integer
    with
        Export        => True,
        Convention    => C,
        External_Name => "gcd_recursive";

    type DiophanticResult is record
        r : Integer;
        x : Integer := 0;
        y : Integer := 0;
    end record
    with
        Convention => C;

    function diophantic_loop(
        a : Integer;
        b : Integer;
        c : Integer) return DiophanticResult
    with
        Export        => True,
        Convention    => C,
        External_Name => "diophantic_loop";

    function diophantic_recursive_call(
        r0 : Integer;
        r1 : Integer;
        c  : Integer) return DiophanticResult
    with
        Export        => True,
        Convention    => C,
        External_Name => "diophantic_recursive";


    function diophantic_recursive(
        r0_in : Integer;
        r1_in : Integer;
        c : Integer;
        s0_in : Integer := 1;
        s1_in : Integer := 0;
        t0_in : Integer := 0;
        t1_in : Integer := 1) return DiophanticResult;

private
end JPPLib;
