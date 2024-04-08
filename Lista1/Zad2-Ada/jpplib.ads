package JPPLib is
    pragma Preelaborate;
    function factorial_loop(n: Integer) return Integer;

    function factorial_recursive(n: Integer) return Integer;

    function gcd_loop(
        a_in: Integer;
        b_in: Integer) return Integer;

    function gcd_recursive(
        a: Integer;
        b: Integer) return Integer;
private
end JPPLib;
